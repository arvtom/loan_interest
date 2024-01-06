#include <fstream>
#include <vector>
#include <map>
#include <limits>
#include <cmath>
#include <cstdio>
#include <chrono>
#include <iostream>

/* Conditions:
    Real estate price:                  100 000 Eur
    Initial contribution:               15 000 Eur
    Credit period:                      30 years
    Bank interest:                      1.8 %
    EURIBOR:                            3.544 %
    Payment method:                     Linnear (lower remaining credit to return =
                                            lower monthly interest payment)
    Credit sum:                         85 000 Eur
    Yearly interest (inc bank taxes):   5.640 %

    The rest of the data is in credit_example.pdf
*/

#define CREDIT_SUM      85000.0     /* Eur */
#define INTEREST        5.640       /* % */
#define CREDIT_PERIOD   30          /* years */

// Warn about use of deprecated functions.
#define GNUPLOT_DEPRECATE_WARN
#include "gnuplot-iostream.h"

#ifndef M_PI
#    define M_PI 3.14159265358979323846
#endif

void demo_png();
