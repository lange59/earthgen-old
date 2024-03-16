#include "terrain.h"
#include "../grid/grid.h"
#include "../../math/math_common.h"
#include "../../math/quaternion.h"
#include <cmath>

namespace earthgen {

void clear_terrain (Terrain& terrain) {
	terrain.tiles.clear();
	terrain.corners.clear();
	terrain.edges.clear();
}

void init_terrain (Terrain& terrain, const Grid& grid) {
	clear_terrain(terrain);
	terrain.tiles.resize(tile_count(grid));
	terrain.corners.resize(corner_count(grid));
	terrain.edges.resize(edge_count(grid));
}

double latitude (const Vector3& v) {
	return std::asin(v.z());
}
double longitude (const Vector3& v) {
	return (v.x() == 0 && v.y() == 0) ? 0 : std::atan2(v.y(), v.x());
}

double latitude (const Terrain& terrain, const Vector3& v) {
	return pi/2 - angle(axis(terrain), v);
}

double longitude (const Terrain& terrain, const Vector3& v) {
	Vector3 u = rotation_to_default(terrain) * v;
	return longitude(u);
}

double north (const Terrain& terrain, const Tile* t) {
	Vector3 v = reference_rotation(t, rotation_to_default(terrain)) * vector(nth_tile(t, 0));
	return pi-atan2(v.y(), v.x());
}

double area (const Terrain& terrain, const Tile* t) {
	double a = 0.0;
	for (int k=0; k<edge_count(t); k++) {
		double angle = acos(dot_product(normal(vector(t) - vector(nth_corner(t,k))), normal(vector(t) - vector(nth_corner(t,k+1)))));
		a += 0.5 * sin(angle) * distance(vector(t), vector(nth_corner(t,k))) * distance(vector(t), vector(nth_corner(t,k+1)));
		/*
		 *	double base = length(corner(t,k)->v - corner(t,k+1)->v);
		 *	double height = length(((corner(t,k)->v + corner(t,k+1)->v) * 0.5) - t->v);
		 *	a += 0.5 * base * height;
		 */
	}
	return a * pow(radius(terrain), 2.0);
}

double length (const Terrain& terrain, const Edge* e) {
	return distance(vector(nth_corner(e,0)), vector(nth_corner(e,1))) * radius(terrain);
}

double angular_velocity (const Terrain&) {
	/* currently locked at 24 hours */
	return 2.0 * pi / (24 * 60 * 60);
}

double coriolis_coefficient (const Terrain& terrain, double latitude) {
	return 2.0 * angular_velocity(terrain) * sin(latitude);
}

Vector3 default_axis () {return Vector3(0,0,1);}

Quaternion rotation (const Terrain& terrain) {
	return rotation_between(default_axis(), axis(terrain));
}

Quaternion rotation_to_default (const Terrain& terrain) {
	return conjugate(rotation(terrain));
}

const std::deque<Terrain_tile>& tiles (const Terrain& t) {return t.tiles;}
const std::deque<Terrain_corner>& corners (const Terrain& t) {return t.corners;}
const std::deque<Terrain_edge>& edges (const Terrain& t) {return t.edges;}

const Terrain_tile& nth_tile (const Terrain& t, int n) {return t.tiles[n];}
const Terrain_corner& nth_corner (const Terrain& t, int n) {return t.corners[n];}
const Terrain_edge& nth_edge (const Terrain& t, int n) {return t.edges[n];}

Terrain_tile& m_tile (Terrain& t, int n) {return t.tiles[n];}
Terrain_corner& m_corner (Terrain& t, int n) {return t.corners[n];}
Terrain_edge& m_edge (Terrain& t, int n) {return t.edges[n];}

}
