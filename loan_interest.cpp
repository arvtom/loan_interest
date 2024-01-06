#include "loan_interest.hpp"

int main() 
{
    // demo_png();

    const std::chrono::time_point now{std::chrono::system_clock::now()};
 
    std::chrono::year_month_day ymd{std::chrono::floor<std::chrono::days>(now)};
 
    std::cout << "Current Year: " << static_cast<int>(ymd.year()) << ", "
                 "Month: " << static_cast<unsigned>(ymd.month()) << ", "
                 "Day: " << static_cast<unsigned>(ymd.day()) << "\n";

    ymd += std::chrono::years(30);

    std::cout << "Current Year: " << static_cast<int>(ymd.year()) << ", "
                 "Month: " << static_cast<unsigned>(ymd.month()) << ", "
                 "Day: " << static_cast<unsigned>(ymd.day()) << "\n";
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