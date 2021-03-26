#include "Grid.hpp"
#include "Mesh.hpp"
#include <Eigen/Dense>
#include <iostream>
#include <vector>

using namespace std;

std::ostream &operator<<(std::ostream &os, const Eigen::Vector3d &v)
{
    for (auto i = 0; i < 3; ++i)
    {
        os << v(i) << std::endl;
    }
    return os;
}

std::ostream &operator<<(std::ostream &os, const std::vector<double> &v)
{

    for (auto i : v)
    {
        os << i << std::endl;
    }
    return os;
}

int main()
{
    Range rng = {0, 10, 20};
    Grid grid(rng);

    Mesh_1D mesh;

    auto a = Eigen::Matrix<double, 3, 3>();
    a << 1, -1. / 4., 0, -1. / 4., 1, -1. / 4., 0, -1. / 4., 1;

    auto t_1 = double(100.0);
    auto t_5 = double(0.0);

    auto old = std::vector<double>({t_1, t_5, t_5, t_5, t_5});

    auto b = Eigen::Vector3d();
    b(0) = t_1 / 4.0 + old[1] / 2.0;
    b(1) = old[2] / 2.0;
    b(2) = t_5 / 4.0 + old[3] / 2.0;

    //    b << t_1 / 4.0 + old[1] / 2.0 , old[2] / 2.0 , t_5 / 4.0 + old[3] / 2.0;

    auto eps = 10E-7;
    auto crit = double(1.0);
    for (auto i = 0; (crit > eps); ++i)
    {
        auto res = a.colPivHouseholderQr().solve(b);

        //        std::cout << res << std::endl;

        old[1] = res(0);
        old[2] = res(1);
        old[3] = res(2);

        b(0) = t_1 / 4.0 + old[1] / 2.0;
        b(1) = old[2] / 2.0;
        b(2) = t_5 / 4.0 + old[3] / 2.0;

        crit = fabs(old[1] - res(0));
    }

    //    a.lu().solve()

    cout << "Hello World!" << endl;
    return 0;
}
