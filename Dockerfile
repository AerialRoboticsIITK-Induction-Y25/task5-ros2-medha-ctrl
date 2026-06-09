# ---------- Builder Stage ----------
FROM osrf/ros:humble-desktop AS builder

SHELL ["/bin/bash", "-c"]

WORKDIR /fleet_ws

COPY . /fleet_ws

RUN source /opt/ros/humble/setup.bash && \
    colcon build

# ---------- Runtime Stage ----------
FROM osrf/ros:humble-desktop

SHELL ["/bin/bash", "-c"]

WORKDIR /fleet_ws

COPY --from=builder /fleet_ws/install /fleet_ws/install

ENTRYPOINT source /opt/ros/humble/setup.bash && \
           source /fleet_ws/install/setup.bash && \
           exec "$@"
