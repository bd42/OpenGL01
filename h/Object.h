class Object
{
    protected:
        float pos[3];
        float anchor[3];
        float rot[3];
        float scale[3];
        float col[3];

    public:
        void SetPosition(float _x, float _y, float _z);
        void Move(float _x, float _y, float _z);
        void SetAnchor(float _x, float _y, float _z);
        void MoveAnchor(float _x, float _y, float _z);
        void SetRotation(float _x, float _y, float _z);
        void Rotate(float _x, float _y, float _z);
        void SetScale(float _x, float _y, float _z);
        void Scale(float _scale);
        void SetColor(float _r, float _g, float _b);
};

class Cube : public Object
{
    private:
        float vert[8][3];
        float norm[24][3];

    public:
        Cube(float _x, float _y, float _z, float _w, float _h, float _d);
        Cube(float _x, float _y, float _z, float _w, float _h, float _d, float _r, float _g, float _b);
        void SetSize(float _w, float _h, float _d);
        void Draw();
};
