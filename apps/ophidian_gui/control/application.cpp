#include "application.h"

namespace apps {

Application::Application()
{

}

Application::~Application()
{
    delete mBuilder;
}

void Application::buildICCAD2017(std::string lef, std::string def, std::string verilog)
{

}

void Application::buildICCAD2015(std::string lef, std::string def, std::string verilog)
{
    mBuilder = new ICCAD2015ContestDesignBuilder(lef, def, verilog);
    mDesign = &mBuilder->build();
    size_t cells = mDesign->netlist().size(ophidian::circuit::Cell());
    size_t pins = mDesign->netlist().size(ophidian::circuit::Pin());
    size_t nets = mDesign->netlist().size(ophidian::circuit::Net());

    emit changeCircuitBox("test", 1, cells, pins, nets);
    emit update();
    std::cout << "Emit update" << std::endl;

}

std::vector<sf::RectangleShape> * Application::cellsContruct(ophidian::geometry::Point windowSize)
{
    std::cout << "Contruindo..." << std::endl;
    if (mDesign == nullptr)
        return nullptr;

    ophidian::geometry::Point chipUpperCorner = mDesign->floorplan().chipUpperRightCorner().toPoint();
    ophidian::geometry::Point scaleFactor(windowSize.x() / chipUpperCorner.x(), windowSize.y() / chipUpperCorner.y());

    std::vector<sf::RectangleShape> * boxes = new std::vector<sf::RectangleShape>();
    boxes->reserve(mDesign->netlist().size(ophidian::circuit::Cell()));

    auto j = 0;
    for (auto cellIt = mDesign->netlist().begin(ophidian::circuit::Cell()); cellIt != mDesign->netlist().end(ophidian::circuit::Cell()); cellIt++)
    {
        auto cellGeometry = mDesign->placementMapping().geometry(*cellIt);

        /*auto cellBox = *cellGeometry.begin();
        sf::RectangleShape shape(sf::Vector2f(cellBox.max_corner().x() - cellBox.min_corner().x(),
                                              cellBox.max_corner().y() - cellBox.min_corner().y()));
        shape.setFillColor(sf::Color(100, 250, 50));
        auto cellLocation = mDesign->placement().cellLocation(*cellIt).toPoint();
        shape.setPosition(cellLocation.x(), cellLocation.y());


        shape.setScale(scaleFactor.x(), scaleFactor.y());

        boxes->push_back(shape);*/
        std::cout << j << " chegou aqui" << std::endl;

        auto i = 0;
        auto cellLocation = mDesign->placement().cellLocation(*cellIt).toPoint();
        for (auto cellBox : cellGeometry)
        {
            sf::RectangleShape shape(sf::Vector2f(cellBox.max_corner().x() - cellBox.min_corner().x(),
                                                  cellBox.max_corner().y() - cellBox.min_corner().y()));
            i += cellBox.max_corner().x() - cellBox.min_corner().x();

            shape.setFillColor(sf::Color(100, 250, 50));
            shape.setPosition(cellLocation.x() + i, cellLocation.y());
            shape.setScale(scaleFactor.x(), scaleFactor.y());

            boxes->push_back(shape);
            std::cout << j <<  ": " << (cellBox.max_corner().x() - cellBox.min_corner().x()) << " x "<< (cellBox.max_corner().y() - cellBox.min_corner().y()) << " - ";
            std::cout << (cellLocation.x() + i) << " . " << cellLocation.y() << std::endl;
        }
        j++;
    }

    return boxes;
}

}