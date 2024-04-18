Color colorByDistance(int distance, float alpha){
    Color _colorByDistance;
    if (distance < 450)
        _colorByDistance = Color(0,255,0, alpha);
    if (distance < 200)
        _colorByDistance = Color(255,255,0, alpha);
    if (distance < 120)
        _colorByDistance = Color(255,133,51, alpha);
    if (distance < 50)
        _colorByDistance = Color(255,0,0, alpha);
    return _colorByDistance;
}

Color colorByDistance2(int distance, float alpha)
{
	Color _colorByDistance2;	
	if (distance < 370)
		_colorByDistance2 = Color(64, 255, 0, alpha);
	if (distance < 350)
		_colorByDistance2 = Color(64, 255, 0, alpha);
	if (distance < 330)
		_colorByDistance2 = Color(64, 255, 0, alpha);
	if (distance < 300)
		_colorByDistance2 = Color(64, 255, 0, alpha);
	if (distance < 290)
		_colorByDistance2 = Color(64, 255, 0, alpha);
	if (distance < 370)
		_colorByDistance2 = Color(64, 255, 0, alpha);
	if (distance < 350)
		_colorByDistance2 = Color(64, 255, 0, alpha);
	if (distance < 330)
		_colorByDistance2 = Color(64, 255, 0, alpha);
	if (distance < 200)
		_colorByDistance2 = Color(255, 191, 0, alpha);
	if (distance < 190)
		_colorByDistance2 = Color(255, 191, 0, alpha);
	if (distance < 180)
		_colorByDistance2 = Color(255, 191, 0, alpha);
	if (distance < 170)
		_colorByDistance2 = Color(255, 191, 0, alpha);
	if (distance < 160)
		_colorByDistance2 = Color(255, 191, 0, alpha);
	if (distance < 150)
		_colorByDistance2 = Color(255, 191, 0, alpha);
	if (distance < 140)
		_colorByDistance2 = Color(255, 191, 0, alpha);
	if (distance < 130)
		_colorByDistance2 = Color(255, 191, 0, alpha);
	if (distance < 120)
		_colorByDistance2 = Color(255, 191, 0, alpha);
	if (distance < 110)
		_colorByDistance2 = Color(255, 128, 0, alpha);
	if (distance < 100)
		_colorByDistance2 = Color(255, 128, 0, alpha);
	if (distance < 90)
		_colorByDistance2 = Color(255, 128, 0, alpha);
	if (distance < 80)
		_colorByDistance2 = Color(255, 128, 0, alpha);
	if (distance < 70)
		_colorByDistance2 = Color(255, 128, 0, alpha);
	if (distance < 60)
		_colorByDistance2 = Color(255, 128, 0, alpha);
	if (distance < 50)
		_colorByDistance2 = Color(255, 64, 0, alpha);
	if (distance < 40)
		_colorByDistance2 = Color(255, 64, 0, alpha);
	if (distance < 30)
		_colorByDistance2 = Color(255, 64, 0, alpha);
	if (distance < 20)
		_colorByDistance2 = Color(255, 64, 0, alpha);
	if (distance < 10)
		_colorByDistance2 = Color(255, 64, 0, alpha);
	return _colorByDistance2;
}