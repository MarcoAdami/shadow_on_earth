# shadow_on_earth

With this project i want to make a code that can determine the lenght of a shadow (hight object: 1 meter) on earth at any given latitude, longitude and time.
I would want to do it in different languages so to compare the implementation and the difference between languages.
Starting with c++, python.

Things to consider:
- System of longitude and latitude
- Earth axis inclination
- Time

Steps:
- conversion degree to radians (radian = degree * pi / 180)
- convert the coordinates in a position of a point on a 3d sphere
    - first setting a point (1,0,0) its position corresponds to the position latitude = 0° and longitude = 0° on earth (in a 3d dimension the x-axis is pointing to you, the y-axis is vertical and the z-azis is orizontal)
    - then using matrices of rotation, first rotate the point for the latitude and then longitude (it's important to do it in this order)
- find the angle beetween the vector of the coordinates found and the previous vector (1, 0, 0), that is the angle of the sun's rays hitting an object on earth, using the formulas : 
    - cos(angle) = (a*b/|a|*|b|)
    - sin(angle) = |a x b|/(|a x b|)
    - tan(angle) = sin(angle) / cos(angle)

- calculate the shadow lenght using the formula: shadow_lenght = obj_hight * tan(angle)


Documentation:
- For matrices: https://en.wikipedia.org/wiki/Rotation_matrix