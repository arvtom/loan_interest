#include "loan_interest.hpp"

int main() 
{
    // demo_png();

    using namespace std::chrono;
    const auto today = sys_days{std::chrono::floor<days>(system_clock::now())};
    for (const year_month_day ymd : {{November/15/2020}, {November/15/2120}, today})
    {
        // std::cout << ymd;
        const auto delta = (sys_days{ymd} - today).count();
        (delta < 0) ? std::cout << " was " << -delta << " day(s) ago\n" :
        (delta > 0) ? std::cout << " is " << delta << " day(s) from now\n"
                    : std::cout << " is today!\n";
    }
}

// void demo_png() 
// {
//     Gnuplot gp;

//     gp << "set terminal png\n";

//     std::vector<double> y_pts;
//     for(int i=0; i<1000; i++) {
//         double y = (i/500.0-1) * (i/500.0-1);
//         y_pts.push_back(y);
//     }

//     std::cout << "Creating my_graph_1.png" << std::endl;
//     gp << "set output 'my_graph_1.png'\n";
//     gp << "plot '-' with lines, sin(x/200) with lines\n";
//     gp.send1d(y_pts);

//     std::vector<std::pair<double, double>> xy_pts_A;
//     for(double x=-2; x<2; x+=0.01) {
//         double y = x*x*x;
//         xy_pts_A.emplace_back(x, y);
//     }

//     std::vector<std::pair<double, double>> xy_pts_B;
//     for(double alpha=0; alpha<1; alpha+=1.0/24.0) {
//         double theta = alpha*2.0*3.14159;
//         xy_pts_B.emplace_back(cos(theta), sin(theta));
//     }

//     std::cout << "Creating my_graph_2.png" << std::endl;
//     gp << "set output 'my_graph_2.png'\n";
//     gp << "set xrange [-2:2]\nset yrange [-2:2]\n";
//     gp << "plot '-' with lines title 'cubic', '-' with points title 'circle'\n";
//     gp.send1d(xy_pts_A);
//     gp.send1d(xy_pts_B);
// }