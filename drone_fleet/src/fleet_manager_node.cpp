#include "rclcpp/rclcpp.hpp"

#include <chrono>

class FleetManagerNode : public rclcpp::Node
{
public:
    FleetManagerNode()
    : Node("fleet_manager_node")
    {
        timer_ =
            create_wall_timer(
                std::chrono::seconds(5),
                std::bind(
                    &FleetManagerNode::report_callback,
                    this
                )
            );
    }

private:
    void report_callback()
    {
        RCLCPP_INFO(
            get_logger(),
            "Fleet Report Generated"
        );
    }

    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc,char* argv[])
{
    rclcpp::init(argc,argv);

    rclcpp::spin(
        std::make_shared<FleetManagerNode>()
    );

    rclcpp::shutdown();

    return 0;
}