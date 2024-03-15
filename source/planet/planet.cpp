#include "planet.h"
#include "grid/grid.h"

namespace earthgen {

Planet::Planet () {
	grid = size_0_grid();
}

void clear (Planet& p) {
	set_grid_size(p, 0);
	clear_terrain(p);
	clear_climate(p);
}

void set_grid_size (Planet& p, int size) {
	p.grid = size_n_grid(size);
}

}
