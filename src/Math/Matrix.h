template<typename T>
struct Matrix4x4
{
    struct index
    {
        int row, col;
        index(int r = 0, int c = 0)
            : row(r), col(c){}
        index(index const & cp)
            : row(cp.row), col(cp.col)
        {
        }
        //Assignment ommited for brevity
    };
    /*
        Constructors, Assignments etc. ommited for brevity
    */
    T m00, m01, m02, m03;
    T m10, m11, m12, m13;
    T m20, m21, m22, m23;
    T m30, m31, m32, m33;

    T * toArray() const
    {
        return &m00;
    }
    T * toArray()
    {
        return &m00;
    }

    T * row(int r)
    {
        return (&m00) + r*4;
    }
    T * row(int r) const
    {
        return (&m00) + r*4;
    }

    T & operator()(int r, int c)
    {
        return *row(r)[c];
    }
    T const & operator()(int r, int c) const
    {
        return *row(r)[c];
    }

    T & operator[](index const & idx)
    {
        return row(idx.row)[idx.col];
    }
    T const & operator[](index const & idx) const
    {
        return row(idx.row)[idx.col];
    }

};