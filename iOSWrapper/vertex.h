#ifndef __Vertex_h
#define __Vertex_h

// Swift/Object-C と点群データをやり取りする際の構造体を定義する
typedef struct {
    float x;
    float y;
    float z;
    float r;
    float g;
    float b;
    float a;
} PointXYZRGBA;

#endif // __Vertex_h