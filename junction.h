#pragma once
class junction
{
public:
	junction(void);
	~junction(void);

	bool is_wall(void);
	void set_wall(void);
	void clear_wall(void);

	float get_time(void);
	void set_time(float);


private:
	bool wall;
	float time;


};

