#include "h/Object.h"

// ======================== 
// =======  Object  =======
// ========================

void Object::SetPosition(float _x, float y, float _z)
{
    pos[0] = _x;
    pos[1] = _y;
    pos[2] = _z;
}

void Object::Move(float _x, float y, float _z)
{
    pos[0] += _x;
    pos[1] += _y;
    pos[2] += _z;
}

void Object::SetAnchor(float _x, float y, float _z)
{
    anchor[0] = _x;
    anchor[1] = _y;
    anchor[2] = _z;
}

void Object::MoveAnchor(float _x, float y, float _z)
{
    anchor[0] += _x;
    anchor[1] += _y;
    anchor[2] += _z;
}

void Object::SetRotation(float _x, float y, float _z)
{
    rot[0] = _x;
    while(rot[0] >= 360.0f)
    { rot[0] -= 360.0f; }
    
    rot[1] = _y;
    while(rot[1] >= 360.0f)
    { rot[1] -= 360.0f; }
    
    rot[2] = _z;
    while(rot[2] >= 360.0f)
    { rot[2] -= 360.0f; }
}

void Object::Rotate(float _x, float y, float _z)
{
    rot[0] += _x;
    while(rot[0] >= 360.0f)
    { rot[0] -= 360.0f; }
    
    rot[1] += _y;
    while(rot[1] >= 360.0f)
    { rot[1] -= 360.0f; }
    
    rot[2] += _z;
    while(rot[2] >= 360.0f)
    { rot[2] -= 360.0f; }
}

void Object::SetScale(float _x, float y, float _z)
{
    scale[0] = _x;
    scale[1] = _y;
    scale[2] = _z;
}

void Object::Scale(float _scale)
{
    scale[0] *= _scale;
    scale[1] *= _scale;
    scale[2] *= _scale;
}

void Object::SetColor(float _r, float _g, float _b)
{
    if(_r < 0.0f)
        col[0] = 0.0f;
    else if (_r > 1.0f)
        col[0] = 1.0f;
    else
        col[0] = _r;

    if(_g < 0.0f)
        col[1] = 0.0f;
    else if (_g > 1.0f)
        col[1] = 1.0f;
    else
        col[1] = _g;

    if(_b < 0.0f)
        col[2] = 0.0f;
    else if (_b > 1.0f)
        col[2] = 1.0f;
    else
        col[2] = _b;
}

// ======================== 
// ========  Cube  ========
// ========================

Cube::Cube(float _x, float _y, float _z, float _w, float _h, float _d)
{
    Cube(_x, _y, _z, _w, _h, _d, 1.0f, 1.0f, 1.0f);
}

Cube::Cube(float _x, float _y, float _z, float _w, float _h, float _d, float _r, float _g, float _b)
{
    SetPosition(_x, _y, _z);
    SetAnchor(_x + _w / 2.0f, _y + _h / 2.0f, _z + _d / 2.0f);
    SetRotation(0.0f, 0.0f, 0.0f);
    SetScale(0.0f, 0.0f, 0.0f);
    SetColor(_r, _g, _b);
    SetSize(_w, _h, _d);
}

void Cube::SetSize(float _w, float _h, float _d)
{
    // TODO
}

void Cube::Draw()
{
    // TODO
}