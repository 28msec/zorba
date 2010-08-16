#include <string> 


void *  
DrawPolygon(const void* aBlob, long* aLength, double aXValues[], double aYValues[], int aNumberOfPoints, const std::string aStrokeColor, const std::string aFillColor, double aStrokeWidth, bool aAntiAliasing); 

void *
DrawPolyLine(const void* aBlob, long* aLength, double aXValues[], double aYValues[], int aNumberOfPoints, std::string aStrokeColor, double aStrokeWidth, bool aAntiAliasing, double aStrokeArray[], int aNumberOfStrokeValues);



template<class T>
  class ZorbaArrayAutoPointer
  {
    private:
      T* thePtr;
  
    public:
      ZorbaArrayAutoPointer(): thePtr(0){}
      explicit ZorbaArrayAutoPointer(T *aPtr): thePtr(aPtr){}
  
      ~ZorbaArrayAutoPointer()
      {
        delete[] thePtr;
      }
  
      void reset(T *aPtr)
      {
        T* lPtr = thePtr;
        thePtr = aPtr;
        if(thePtr != 0)
        {
          delete[] lPtr;
        }
      }
  
      T* get() const
      {
        return thePtr;
      }
      T* release()
      {
        T* lPtr = thePtr;
        thePtr = 0;
        return lPtr;
      }
      T operator[](unsigned int anIndex) const
      {
        return thePtr[anIndex];
      }
  };
