#include "loan_interest.hpp"

void demo_png() {
    Gnuplot gp;

    gp << "set terminal png\n";

    std::vector<double> y_pts;
    for(int i=0; i<1000; i++) {
        double y = (i/500.0-1) * (i/500.0-1);
        y_pts.push_back(y);
    }

    std::cout << "Creating my_graph_1.png" << std::endl;
    gp << "set output 'my_graph_1.png'\n";
    gp << "plot '-' with lines, sin(x/200) with lines\n";
    gp.send1d(y_pts);

    std::vector<std::pair<double, double>> xy_pts_A;
    for(double x=-2; x<2; x+=0.01) {
        double y = x*x*x;
        xy_pts_A.emplace_back(x, y);
    }

    std::vector<std::pair<double, double>> xy_pts_B;
    for(double alpha=0; alpha<1; alpha+=1.0/24.0) {
        double theta = alpha*2.0*3.14159;
        xy_pts_B.emplace_back(cos(theta), sin(theta));
    }

    std::cout << "Creating my_graph_2.png" << std::endl;
    gp << "set output 'my_graph_2.png'\n";
    gp << "set xrange [-2:2]\nset yrange [-2:2]\n";
    gp << "plot '-' with lines title 'cubic', '-' with points title 'circle'\n";
    gp.send1d(xy_pts_A);
    gp.send1d(xy_pts_B);
}

int main(int argc, char **argv) {
    std::map<std::string, void (*)(void)> demos;

    // demos["basic"]                  = demo_basic;
    // demos["binary"]                 = demo_binary;
    // demos["tmpfile"]                = demo_tmpfile;
    demos["png"]                    = demo_png;
    // demos["vectors"]                = demo_vectors;
    // demos["script_inline_text"]     = demo_inline_text;
    // demos["script_inline_binary"]   = demo_inline_binary;
    // demos["script_external_text"]   = demo_external_text;
    // demos["script_external_binary"] = demo_external_binary;
    // demos["animation"]              = demo_animation;
    // demos["nan"]                    = demo_NaN;
    // demos["segments"]               = demo_segments;
    // demos["image"]                  = demo_image;
    // demos["plotgroup"]              = demo_plotgroup;
    // demos["fit"]                    = demo_fit;

    if(argc < 2) {
        printf("Usage: %s <demo_name>\n", argv[0]);
        printf("Choose one of the following demos:\n");
        typedef std::pair<std::string, void (*)(void)> demo_pair;
        for(const demo_pair &pair : demos) {
            printf("    %s\n", pair.first.c_str());
        }
        return 0;
    }

    std::string arg(argv[1]);
    if(!demos.count(arg)) {
        printf("No such demo '%s'\n", arg.c_str());
        return 1;
    }

    demos[arg]();
}
