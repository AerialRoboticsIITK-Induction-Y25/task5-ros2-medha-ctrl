from launch import LaunchDescription

from launch_ros.actions import Node


def generate_launch_description():

    return LaunchDescription([

        Node(
            package="drone_fleet",
            executable="drone_node",
            name="alpha",
            parameters=[
                {"drone_name":"Alpha"},
                {"initial_battery":100.0}
            ]
        ),

        Node(
            package="drone_fleet",
            executable="drone_node",
            name="beta",
            parameters=[
                {"drone_name":"Beta"},
                {"initial_battery":60.0}
            ]
        ),

        Node(
            package="drone_fleet",
            executable="drone_node",
            name="gamma",
            parameters=[
                {"drone_name":"Gamma"},
                {"initial_battery":15.0}
            ]
        ),

        Node(
            package="drone_fleet",
            executable="fleet_manager_node",
            name="fleet_manager"
        ),

        Node(
            package="drone_fleet",
            executable="diagnostics_node",
            name="diagnostics"
        )

    ])