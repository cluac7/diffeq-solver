#include <cmath>
#include <iostream>
#include <numbers>

// EQUATION:
// \ddot \theta (t) = -\mu \dot \theta (t) - \frac{g}{L}\sin(\theta(t))
// theta(t)... uncalcuable, that's why this exists

// Physical Consts
constexpr double g = 9.81;
constexpr double L = 0.4;
constexpr double mu = 0.1;

constexpr double THETA_0=std::numbers::pi/2;
constexpr double THETA_DOT_0 = 0.0;

auto theta_ddot(double theta, double theta_dot) -> double{
  return -mu * theta_dot - (g/L) * std::sin(theta);
}

// solution to equation
auto theta(double time, double timestep) -> double {
  double theta = THETA_0;
  double theta_dot = THETA_DOT_0;

  for (double i=timestep; i <= time; i+=timestep) {
    theta+=theta_dot*timestep;
    theta_dot+=theta_ddot(theta, theta_dot)*timestep;

    std::cout << "time: " << i*timestep << "s angle: " << theta << "rad velocity: " << theta_dot << "rad/s\n";
  }
  
  return theta;
}

int main() {
  std::cout << "enter a total time (s), accuracy (s^-1): " << std::endl;
  double total_time, accuracy, timestep;
  std::cin >> total_time >> accuracy;
  timestep = 1.0/accuracy;

  theta(total_time, timestep);

  return 0;
}
