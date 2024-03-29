#include "loan_interest.hpp"

int main() 
{
    // demo_png();

    std::chrono::time_point now{std::chrono::system_clock::now()};
    std::chrono::year_month_day ymd_0{std::chrono::floor<std::chrono::days>(now)};
    std::chrono::year_month_day ymd_1{std::chrono::floor<std::chrono::days>(now)};

    std::chrono::year_month_day last_ymd{std::chrono::floor<std::chrono::days>(now)};
    std::chrono::year_month_day this_ymd{std::chrono::floor<std::chrono::days>(now)};
    std::vector<double> days;
    std::vector<double> interests;

    ymd_1 += std::chrono::years(CREDIT_PERIOD_YEARS);

    double credit_period_days = 
        (std::chrono::sys_days{ymd_1} - std::chrono::sys_days{ymd_0}).count();

    /* Find interest for each month */
    for (uint16_t month = 0u; month < 12u; month++)
    {
        this_ymd += std::chrono::months(1);

        days.push_back(
            (std::chrono::sys_days{this_ymd} - std::chrono::sys_days{last_ymd}).count()
        );

        interests.push_back(
            CREDIT / credit_period_days * days.back() * INTEREST
        );

        last_ymd = this_ymd;
    }

    double total_interest = CREDIT / 100.0 * INTEREST;
    double total_payments = CREDIT + INTEREST;

    fprintf(stdout, "credit_period_days=%.2f Eur\n", credit_period_days);
    fprintf(stdout, "total_interest=%.2f Eur\n", total_interest);
    fprintf(stdout, "total_payments=%.2f Eur\n", total_payments);

    for (uint16_t month = 0u; month < 12u; month++)
    {
        std::cout 
            << "days=" << days.at(month)
            << ", interests=" << interests.at(month) << "\n"
        ;
    }

    //     for (double i: days)
    // {
    //     std::cout 
    //         << "days=" << i << "\n"
    //         << "interest=" << i << "\n"
    // }
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