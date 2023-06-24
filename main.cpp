#include "color.h"
#include "ray.h"
#include "vec3.h"
#include "sphere.h"
#include <math.h>
#include <fstream>
#include <vector>
#include <sstream>     

using namespace std;

pair<int, double> intersection(const vector<Sphere>& objects, const Ray& ray) { 
    double min_root = -1.0;
    int index = -1;
    for ( int k=0; k<objects.size(); ++k ) {
        Sphere sp = objects.at(k);
        double a = dot(ray.direction(), ray.direction());
        Vec3 originToCenter = ray.origin() - sp.center();
        double b = 2.0*dot(ray.direction(), originToCenter);
        double c = dot(originToCenter, originToCenter) - sp.radius()*sp.radius();
        double discriminant = b*b - 4*a*c;
    
        if (discriminant < 0) {
            continue;
        }

        double root = (-b - sqrt(discriminant) ) / (2.0*a);

        if (min_root == -1 || root < min_root) {
            min_root = root;
            index = k;
        }

    }
    return make_pair(index,min_root);
}

vector<Sphere> read_file(){
    vector<Sphere> objects;
    ifstream myfile ("input.txt");
    string line;
    if (myfile.is_open())
    {
        getline (myfile,line);        
        while (getline (myfile,line) )
        {
            istringstream ss(line);
  
            string x; 
            string y;
            string z;
            ss >> x;
            ss >> y;
            ss >> z;
            Vec3 color = Vec3(stod(x), stod(y), stod(z));
            
            getline (myfile,line);
            istringstream ss1(line);
            ss1 >> x;
            ss1 >> y;
            ss1 >> z;
            Vec3 pos = Vec3(stod(x), stod(y), stod(z));

            
            getline (myfile,line);
            istringstream ss2(line);
            ss2 >> x;
            double radius = stod(x);

            objects.push_back(Sphere(pos,radius,color));
        }
        myfile.close();
    }
    return objects;
}
int main() {
    vector<Sphere> objects = read_file();
    Vec3 eye_point = Vec3(0,0,0);
    double pixel_step = 100.0/1000;
    Vec3 left_lower_corner = Vec3(-50.0, -50.0, 100.0) + Vec3(pixel_step/2.0, pixel_step/2.0, 0);
    cout << "P3\n" << 1000 << " " << 1000 << "\n255\n";

    Vec3 light = Vec3(500,500,500);

    for (int j = 0; j < 1000; ++j) {
        for (int i = 0; i < 1000; ++i ) {
            Vec3 pixel_loc = left_lower_corner + Vec3(pixel_step*i,pixel_step*j,0);
            Vec3 eye_to_pixel = pixel_loc - eye_point;
            Ray from_pixel(eye_point, unit_vector(eye_to_pixel));
            
            pair<int, double> result = intersection(objects, from_pixel);
            double t = result.second;

            if(t >= 0){
                Sphere sp = objects.at(result.first);
                
                Vec3 point = from_pixel.at(t);
                Vec3 light_dir = point - light;
                Ray light_r = Ray(light, unit_vector(light_dir));
                
                pair<int, double> result2 = intersection(objects, light_r);
                double t2 = result2.second;
                Vec3 point_int = light_r.at(t2);
                
                if(abs(point_int.x() - point.x()) < 1) {
                    write_color(cout,sp.color());
                }
                else {
                    write_color(cout ,sp.color()*0.1);
                } 
            }
            else {
                write_color(cout ,Vec3(255*0.3,255*0.5,255*0.1));
            }
        }
    }

}