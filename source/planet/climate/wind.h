#ifndef wind_h
#define wind_h

namespace earthgen {

class Wind {
public:
	Wind () :
		direction (0), speed (0) {}

	float direction;
	float speed;
};

}

#endif
