/* taum-and-bday.cpp
 * https://www.hackerrank.com/challenges/taum-and-bday
 */
#include <iostream>
using namespace std;

int main()
{
    int t;
    int b_num, w_num;
    long b_cost, w_cost, conv_cost;
    long b_best_cost, w_best_cost;
    long tot_cost;

    cin >> t;
    while (t--)
    {
        cin >> b_num >> w_num;
        cin >> b_cost >> w_cost >> conv_cost;

        b_best_cost = min(b_cost, w_cost + conv_cost);
        w_best_cost = min(w_cost, b_cost + conv_cost);
        tot_cost = b_num * b_best_cost + w_num * w_best_cost;

        cout << tot_cost << endl;
    }
    return 0;
}
