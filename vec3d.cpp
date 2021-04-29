#include <cstdlib>
#include <cstdio>
#include <cmath>

class vec3d {
  private:
    double x, y, z;

  public:
    vec3d() {
      x = 0;
      y = 0;
      z = 0;
    }
    vec3d(double _x, double _y, double _z) {
      x = _x;
      y = _y;
      z = _z;
    }
    void set(double _x, double _y, double _z) {
      x = _x;
      y = _y;
      z = _z;
    }

    //正規化
    void normalize() {
      double vec3d_len = length();
			x /= vec3d_len;
			y /= vec3d_len;
			z /= vec3d_len;
    }

		//ベクトルの長さを取得
		double length() {
			return (
				sqrt(x * x + y * y + z * z)
			);
		}

		//長さをn倍にする
		void scale(const double n) {
			x *= n;
			y *= n;
			z *= n;
		}

		vec3d operator+(vec3d v) {
			return (
				vec3d(x + v.x, y + v.y, z + v.z)
			);
		}

		vec3d operator-(vec3d v) {
			return (
				vec3d(x - v.x, y - v.y, z - v.z)
			);
		}

		//内積
		double operator*(vec3d v) {
			return (x * v.x + y * v.y + z * v.z);
		}

		//外積
		vec3d operator%(vec3d v) {
			return (
				vec3d(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x)
			);
		}

		vec3d& operator=(vec3d& v) {
			x = v.x;
			y = v.y;
			z = v.z;
			return (*this);
		}

		vec3d& operator+=(vec3d& v) {
			x += v.x;
			y += v.y;
			z += v.z;
			return (*this);
		}

		vec3d& operator-=(vec3d& v) {
			x -= v.x;
			y -= v.y;
			z -= v.z;
			return (*this);
		}

		void print() {
			printf("vec3d(%f, %f, %f)", x, y, z);
		}
};
