#include "rclcpp/rclcpp.hpp"

#include <chrono>

class DiagnosticsNode : public rclcpp::Node
{
public:
    DiagnosticsNode()
    : Node("diagnostics_node")
    {
        timer_ =
            create_wall_timer(
                std::chrono::seconds(10),
                std::bind(
                    &DiagnosticsNode::diagnostics_callback,
                    this
                )
            );
    }

private:
    void diagnostics_callback()
    {
        RCLCPP_INFO(
            get_logger(),
            "Health Diagnostics Running"
        );
    }

    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc,char* argv[])
{
    rclcpp::init(argc,argv);

    rclcpp::spin(
        std::make_shared<DiagnosticsNode>()
    );

    rclcpp::shutdown();

    return 0;
}