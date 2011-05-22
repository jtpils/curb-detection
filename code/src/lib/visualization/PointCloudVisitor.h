#ifndef POINTCLOUDVISITOR_H
#define POINTCLOUDVISITOR_H

#include "Visitor.h"

#include <GL/gl.h>

#include <iosfwd>

class PointCloudETH;
class Point3D;

class PointCloudVisitor : public Visitor {
  friend std::ostream& operator << (std::ostream& stream,
    const PointCloudVisitor& obj);
  friend std::istream& operator >> (std::istream& stream,
    PointCloudVisitor& obj);
  friend std::ofstream& operator << (std::ofstream& stream,
    const PointCloudVisitor& obj);
  friend std::ifstream& operator >> (std::ifstream& stream,
    PointCloudVisitor& obj);

  PointCloudVisitor(const PointCloudVisitor& other);
  PointCloudVisitor& operator = (const PointCloudVisitor& other);

  virtual void read(std::istream& stream);
  virtual void write(std::ostream& stream) const;
  virtual void read(std::ifstream& stream);
  virtual void write(std::ofstream& stream) const;

  double mf64PointSize;
  Color mColor;

public:
  PointCloudVisitor(double f64PointSize = 1.0, GLbyte redColorByte = 0,
    GLbyte greenColorByte = 0, GLbyte blueColorByte = 1);
  ~PointCloudVisitor();

  void visit(const PointCloudETH* pointCloud);
  void visit(const Point3D* point3D) const;
  void setPointSize(double f64PointSize);
  double getPointSize() const;

protected:

};

#endif // POINTCLOUDVISITOR_H
