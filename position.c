#include <stdlib.h>
#include "position.h"

int calculateDistance(const Field *field, const Position *position){
    int distance;
    distance = abs(field->submarine.row+1-position->row)+abs(field->submarine.col+65-position->col);
    return distance;
}
