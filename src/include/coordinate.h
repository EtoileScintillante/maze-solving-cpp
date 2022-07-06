/*                                  
 * coordinate.h
 *
 * Created on: 6 July 2022
 * Author: EtoileScintillante
 */

#ifndef __COORDINATE__
#define __COORDINATE__

class Coordinate {
public:
    int x, y;
    Coordinate();
    Coordinate(int a, int b);
    bool operator == (Coordinate c);
};

#endif /*__COORDINATE__*/