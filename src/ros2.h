/************************************************************************
**  MODULE:        ROS2.H
**  PROJECT:       EPANET-MSX
**  DESCRIPTION:   Header file for the stiff ODE solver ROS2.C.
**  AUTHOR:        L. Rossman, US EPA - NRMRL
**  VERSION:       1.1.00                                               
**  LAST UPDATE:   3/1/07
***********************************************************************/

typedef struct {

    double** A;                     // Jacobian matrix
    double* K1;                    // Intermediate solutions
    double* K2;
    double* Ynew;                  // Updated function values
    int*    Jindx;                 // Jacobian column indexes
    int     Nmax;                  // Max. number of equations
    int     Adjust;                // use adjustable step size
}MSXRosenbrock;

// Opens the ODE solver system
int  ros2_open(int n, int adjust);

// Closes the ODE solver system
void ros2_close(void);

// Applies the solver to integrate a specific system of ODEs
int  ros2_integrate(double y[], int n, double t, double tnext,
                    double* htry, double atol[], double rtol[],
                    void (*func)(double, double*, int, double*));
