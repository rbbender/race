#include <imgui.h>
#include <imgui-SFML.h>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/CircleShape.hpp>

constexpr unsigned wnd_width = 640;
constexpr unsigned wnd_height = 480;
constexpr unsigned framerate_cap = 60;
constexpr float radius = 100.F;

int main()
{
  sf::RenderWindow window(sf::VideoMode(wnd_width, wnd_height), "ImGui + SFML = <3");
  window.setFramerateLimit(framerate_cap);
  ImGui::SFML::Init(window);

  sf::CircleShape shape(radius);
  shape.setFillColor(sf::Color::Green);

  sf::Clock deltaClock;
  while (window.isOpen()) {
    sf::Event event{};
    while (window.pollEvent(event)) {
      ImGui::SFML::ProcessEvent(event);

      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    ImGui::SFML::Update(window, deltaClock.restart());

//    ImGui::ShowDemoWindow();

    ImGui::Begin("Hello, world!");
    ImGui::Button("Look at this pretty button");
    ImGui::End();

    window.clear();
    window.draw(shape);
    ImGui::SFML::Render(window);
    window.display();
  }

  ImGui::SFML::Shutdown();

  return 0;
}
