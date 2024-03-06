#if !defined(_SGFX_TYPES_H_)
#define _SGFX_TYPES_H_

template<typename T>
class sgfxVec4
{
public:
	sgfxVec4(T xX, T yY, T zZ, T wW)
		: x(xX), y(yY), z(zZ), w(wW)
	{}
	T x, y, z, w;
	sgfxVec4<T> operator+(sgfxVec4<T>& addVec)
	{
		return sgfxVec4(x + addVec.x, y + addVec.y, z + addVec.z, w + addVec.w);
	}
	sgfxVec4<T> operator-(sgfxVec4<T>& subVec)
	{
		return sgfxVec4(x - subVec.x, y - subVec.y, z - subVec.z, w - subVec.w);
	}
	sgfxVec4<T> operator*(T mul)
	{
		return sgfxVec4(x * mul, y * mul, z * mul, w * mul);
	}
};


#endif