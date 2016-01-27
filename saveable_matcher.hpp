/*  Derived class of FlannBasedMatcher to facilitate saving and loading of the KD tree.
**  Based on the solution at:
**    http://stackoverflow.com/questions/9248012/saving-and-loading-flannbasedmatcher?rq=1
**
**  To save a FlannBasedMatcher:
**    - Save the IndexParams and SearchParams using FlannBasedMatcher::read and write
**    - Save the flannIndex which is a protected member of FlannBasedMatcher, and
**      hence why a derived class is required to access this protected member.
*/
#include <opencv2/opencv.hpp>

using namespace cv;
class SaveableFlannBasedMatcher : public cv::FlannBasedMatcher
{
public:

  SaveableFlannBasedMatcher(const char* _filename);
  virtual ~SaveableFlannBasedMatcher(){};

  void printParams();
  virtual void store();
  virtual void load();

protected:
  const char* filename;
  void readIndex(const char* name);
  void writeIndex(const char* name);
  void writeDescriptors(std::vector<Mat> descriptors, const char* name);
  void readDescriptors(std::vector<Mat> &descriptors, const char* name);
};
