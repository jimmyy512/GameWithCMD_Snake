#include <windows.h>
using namespace std;

class snake_body
{
private:
	COORD body,old_body;
	snake_body* pnext;
public:
	snake_body(int _x, int _y)
	{
		body.X = _x;
		body.Y = _y;
		pnext = NULL;
	}
	snake_body()
	{
		pnext = NULL;
	}
	SHORT get_x()
	{
		return body.X;
	}
	SHORT get_y()
	{
		return body.Y;
	}
	void set_xy(int _x, int _y)
	{
		body.X = _x;
		body.Y = _y;
		pnext = NULL;
	}
	void set_body(COORD& get_current)
	{
		body = get_current;
	}
	void set_old_body(COORD& get_old)
	{
		old_body = get_old;
	}
	void set_next(snake_body* pb)
	{
		pnext = pb;
	}
	snake_body* get_pnext()
	{
		return pnext;
	}
	COORD get_old_body()
	{
		return old_body;
	}
	COORD get_body()
	{
		return body;
	}

};