#include <stdio.h>

struct Rectangle
{
    float width, height, area;
};

void update_rectangle(struct Rectangle *p);
void update_width(float new_width, struct Rectangle *p);
void update_height(float new_height, struct Rectangle *p);
void print_rectangle_data(struct Rectangle rectangle);

int main()
{
    float new_height, new_width;
    new_height = 10;
    new_width = 20;

    struct Rectangle rec, *ptr;
    ptr = &rec;

    /*
    scanf("\n%f %f", &rec.width, &rec.height);
    update_rectangle(ptr);
    printf("\n%f", rec.height);
    printf("\n%f", rec.area);

    update_height(new_height, ptr);
    printf("\n%f", rec.height);

    update_width(new_width, ptr);
    printf("\n%f", rec.width);

    printf("\n%f", rec.area);

    print_rectangle_data(rec);
    */

    return 0;
}


void update_rectangle(struct Rectangle *p)
{
    if (p->width >= 0 && p->height >= 0)
    {
        p->area = p->width * p->height;
    }
    else
    {
        printf("\nBADVALUE: width and height should be >= 0\n");
    }
    
}


void update_width(float new_width, struct Rectangle *p)
{   
    if (new_width >= 0)
    {
        p->width = new_width;
        update_rectangle(p);
    } 
    else 
    {
        printf("\nBADVALUE: new width should be >= 0\n");
    }

}



void update_height(float new_height, struct Rectangle *p)
{   
    if (new_height >= 0)
    {
        p->height = new_height;
        update_rectangle(p);
    } 
    else 
    {
        printf("\nBADVALUE: new height should be >= 0\n");
    }

}

void print_rectangle_data(struct Rectangle rectangle)
{
    printf("\nlargura: %f | altura: %f | area: %f\n", rectangle.width, rectangle.height, rectangle.area);
}
