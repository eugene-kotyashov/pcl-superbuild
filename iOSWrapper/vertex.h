#ifndef __Vertex_h
#define __Vertex_h

// Swift/Object-C と点群データをやり取りする際の構造体を定義する
struct SwiftPointXYZRGBA{
    float x;
    float y;
    float z;
    float r;
    float g;
    float b;
    float a;
};
typedef struct SwiftPointXYZRGBA SwiftPointXYZRGBA;

struct SwiftPointXYZ {
    float x;
    float y;
    float z;
};

#endif // __Vertex_h