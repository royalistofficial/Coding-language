#include "const.hpp"

class Battlefield {
public:
    Battlefield();
    void newIterationBattlefield();
    Plarform* getPlatform();
    ~Battlefield();
private:
    Grid *grid;
    Plarform *plarform;
    std::vector<Ball*> balls;
    std::vector<Bonus*> bonuses;
};
