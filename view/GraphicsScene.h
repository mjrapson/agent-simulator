#pragma once

#include <QGraphicsScene>

#include <memory>
#include <vector>

namespace view
{
class AgentItem;
class GraphicsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit GraphicsScene(QObject *parent = nullptr);
    ~GraphicsScene();

    void addAgent(std::unique_ptr<AgentItem> agent);

    void update();

private:
    std::vector<std::unique_ptr<AgentItem>> m_agents;
};
}
