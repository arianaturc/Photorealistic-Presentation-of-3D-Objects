#include "Camera.hpp"

namespace gps {

    //Camera constructor
    Camera::Camera(glm::vec3 cameraPosition, glm::vec3 cameraTarget, glm::vec3 cameraUp) {
        //TODO
        this->cameraPosition = cameraPosition;
        this->cameraTarget = cameraTarget;
        this->cameraUpDirection = cameraUp;
        
    }

    //return the view matrix, using the glm::lookAt() function
    glm::mat4 Camera::getViewMatrix() {
        //TODO

        return glm::lookAt(cameraPosition, cameraTarget, this->cameraUpDirection);
    }

    //update the camera internal parameters following a camera move event
    void Camera::move(MOVE_DIRECTION direction, float speed) {
        //TODO
        glm::vec3 front = glm::normalize(cameraTarget - cameraPosition);
        glm::vec3 right = glm::normalize(glm::cross(front, cameraUpDirection));

        glm::vec3 delta(0.0f);

        switch (direction) {
            case MOVE_FORWARD:  delta = front * speed; break;
            case MOVE_BACKWARD: delta = -front * speed; break;
            case MOVE_LEFT:     delta = -right * speed; break;
            case MOVE_RIGHT:    delta = right * speed; break;
        }

        cameraPosition += delta;
        cameraTarget += delta;

    }

    //update the camera internal parameters following a camera rotate event
    //yaw - camera rotation around the y axis
    //pitch - camera rotation around the x axis
    void Camera::rotate(float pitch, float yaw) {
        //TODO
        glm::vec3 dir = cameraTarget - cameraPosition;

        glm::mat4 yawRot = glm::rotate(glm::mat4(1.0f), glm::radians(yaw), cameraUpDirection);
        dir = glm::vec3(yawRot * glm::vec4(dir, 0.0f));

        glm::vec3 right = glm::normalize(glm::cross(glm::normalize(dir), cameraUpDirection));
        glm::mat4 pitchRot = glm::rotate(glm::mat4(1.0f), glm::radians(pitch), right);
        dir = glm::vec3(pitchRot * glm::vec4(dir, 0.0f));

        cameraTarget = cameraPosition + dir;
    }
}
