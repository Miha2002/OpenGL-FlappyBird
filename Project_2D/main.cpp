#include <iostream>
#include <windows.h>
#include <GL/freeglut.h>
#include <string>
#include <fstream>
#include <cmath>

using namespace std;

GLdouble left_m = -50.0;
GLdouble right_m = 850.0;
GLdouble bottom_m = -100.0;
GLdouble top_m = 650.0;

double ok = 1;
double j = 360.0;
double i = 0.0;
double contor = 0;
double loc_vert = 1000;
double loc_nori = 1500;
int vector[5] = { 120, 240, 360, 480, 600 };
double height = vector[rand() % 5];
double sheesh = vector[rand() % 3] + 300;
double sheesh2 = vector[rand() % 3] + 300;
double sheesh3 = vector[rand() % 3] + 300;
int score = 0;
double timp = 0.3;
double timp_nori = 0.2;
int pct = 1000;
double rsj, rdj, rss, rds = 0;

int jocActiv = 0;
int soundPoint = 0;
int grad = 1;

int highscore;
string s;
int readOnce = 0;
fstream file("score.txt", ios::in);


void init(void)
{
	//PlaySound(TEXT("song.wav"), NULL, SND_ASYNC | SND_LOOP);
	glMatrixMode(GL_PROJECTION);
	glOrtho(left_m, right_m, bottom_m, top_m, -1.0, 1.0);
}

void RenderString(float x, float y, void* font, const unsigned char* string)
{
	glColor3f(0.0f, 0.0f, 0.0f);
	glRasterPos2f(x, y);

	glutBitmapString(font, string);
}

void startgame(void)
{
	if ((height == j || (loc_vert > 60 || loc_vert < -80))&& ok == 1)
	{
		if (i < -380)
		{
			i = 0;
		}
		i = i - 2 * timp;

		loc_vert -= timp;
		
		if (loc_vert < -80 && soundPoint == 0)
		{
			PlaySound(TEXT("point.wav"), NULL, SND_ASYNC);
			soundPoint = 1;
		}

		if (loc_vert < -150)
		{
			score += 100;
			soundPoint = 0;
			height = vector[rand() % 5];
			cout << "Score:  " << score << endl;
			loc_vert = 1000;
		}

		if (score >= pct && pct <= 20000)
		{
			timp += 0.05;
			timp_nori += 0.05;
			pct += 1000;
		}

		glutPostRedisplay();
	}
	else if(ok==1 && jocActiv==1){
		ok = 0;
		if (score > highscore)
		{ 
			highscore = score;

			// Afisare highscore
			ofstream fileOut("score.txt", ios::trunc);
			fileOut << highscore << "\n";
			fileOut.close();
		}
		PlaySound(TEXT("wasted.wav"), NULL, SND_ASYNC);
	}
	else { ok = 0; }

	loc_nori -= timp_nori;

	if (loc_nori < -700)
	{
		sheesh = vector[rand() % 3] + 300;
		sheesh2 = vector[rand() % 3] + 200;
		sheesh3 = vector[rand() % 3] + 100;
		loc_nori = 1500;
	}
}

void drawScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	// BG color
	if (score%2500 < 500) {
		glClearColor(0.56, 0.94, 0.92, 0.0); // Sky blue: 143, 242, 236
	}
	else if (score % 2500 >= 500 && score % 2500 < 1000) {
		glClearColor(0.65, 0.65, 1.0, 0.0); // Sundown
	}
	else if (score%2500 >= 1000 && score%2500 < 1500) {
		glClearColor(0.25, 0.25, 0.40, 0.0); //Night
	}
	else if (score%2500 >= 1500 && score%2500 < 2000) {
		glClearColor(0.65, 0.65, 1.0, 0.0); // Sunrise
	}
	else {
		glClearColor(0.56, 0.94, 0.92, 0.0); // Sky blue: 143, 242, 236
	}
	
	// Culoare nori
	if (score%2500 < 500) {
		glColor3f(0.95, 0.95, 0.95); // Day
	}
	else if (score%2500 >= 500 && score%2500 < 1000) {
		glColor3f(0.95, 0.65, 0.95); // Sundown
	}
	else if (score%2500 >= 1000 && score%2500 < 1500) {
		glColor3f(0.30, 0.30, 0.70); // Night
	}
	else if (score%2500 >= 1500 && score%2500 < 2000) {
		glColor3f(0.95, 0.65, 0.95); // Sunrise
	}
	else {
		glColor3f(0.95, 0.95, 0.95); // Day
	}

	// Desenam nori
	glPushMatrix();
	glTranslated(loc_nori + 100, 0.0, 0.0);

	glRecti(-40, sheesh, 0, sheesh + 40);
	glRecti(0, sheesh, 80, sheesh + 60);
	glRecti(80, sheesh, 120, sheesh + 40);
	glPopMatrix();
	
	// NOR 2
	glPushMatrix();
	glTranslated(loc_nori - 500, 0.0, 0.0);

	glRecti(-40, sheesh2, 0, sheesh2 + 40);
	glRecti(0, sheesh2, 80, sheesh2 + 60);
	glRecti(80, sheesh2, 120, sheesh2 + 40);
	glPopMatrix();

	//NOR3
	glPushMatrix();
	glTranslated(loc_nori + 500, 0.0, 0.0);

	glRecti(-40, sheesh3, 0, sheesh3 + 40);
	glRecti(0, sheesh3, 80, sheesh3 + 60);
	glRecti(80, sheesh3, 120, sheesh3 + 40);
	glPopMatrix();

	// Cladiri in bg
	glPushMatrix();
	if (score%2500 < 500) {
		glColor3f(0.50, 0.90, 0.85); // Day
	}
	else if (score%2500 >= 500 && score%2500 < 1000) {
		glColor3f(0.50, 0.50, 0.85); // Sundown
	}
	else if (score%2500 >= 1000 && score%2500 < 1500) {
		glColor3f(0.20, 0.20, 0.35); // Night
	}
	else if (score%2500 >= 1500 && score%2500 < 2000) {
		glColor3f(0.50, 0.50, 0.85); // Sunrise
	}
	else {
		glColor3f(0.50, 0.90, 0.85); // Day
	}

	glRecti(-100, 60, -10, 320);
	glRecti(-40, 60, 40, 220);
	glRecti(50, 60, 100, 300);
	glRecti(100, 60, 140, 200);
	glRecti(150, 60, 250, 280);
	glRecti(250, 60, 300, 240);
	glRecti(310, 60, 340, 360);
	glRecti(350, 60, 400, 300);
	glRecti(400, 60, 450, 200);
	glRecti(460, 60, 490, 360);
	glRecti(500, 60, 600, 280);
	glRecti(600, 60, 650, 310);
	glRecti(660, 60, 700, 280);
	glRecti(700, 60, 790, 260);
	glRecti(800, 60, 850, 350);

	// Closer
	glPopMatrix();
	if (score%2500 < 500) {
		glColor3f(0.45, 0.85, 0.80); // Day
	}
	else if (score%2500 >= 500 && score%2500 < 1000) {
		glColor3f(0.45, 0.45, 0.80); // Sundown
	}
	else if (score%2500 >= 1000 && score%2500 < 1500) {
		glColor3f(0.15, 0.15, 0.30); // Night
	}
	else if (score%2500 >= 1500 && score%2500 < 2000) {
		glColor3f(0.45, 0.45, 0.80); // Sunrise
	}
	else {
		glColor3f(0.45, 0.85, 0.80); // Day
	}

	glPushMatrix();
	glRecti(-100, 0, 0, 250);
	glRecti(-50, 60, 30, 150);
	glRecti(30, 60, 90, 200);
	glRecti(100, 60, 160, 170);
	glRecti(160, 60, 280, 210);
	glRecti(290, 60, 330, 220);
	glRecti(330, 60, 400, 180);
	glRecti(400, 60, 460, 200);
	glRecti(470, 60, 520, 180);
	glRecti(530, 60, 580, 250);
	glRecti(580, 60, 600, 150);
	glRecti(610, 60, 700, 230);
	glRecti(710, 60, 750, 150);
	glRecti(750, 60, 780, 170);
	glRecti(780, 60, 900, 220);

	glPopMatrix();

	// Closest
	glPushMatrix();
	if (score%2500 < 500) {
		glColor3f(0.40, 0.80, 0.75); // Day
	}
	else if (score%2500 >= 500 && score%2500 < 1000) {
		glColor3f(0.40, 0.40, 0.75); // Sundown
	}
	else if (score%2500 >= 1000 && score%2500 < 1500) {
		glColor3f(0.10, 0.10, 0.25); // Night
	}
	else if (score%2500 >= 1500 && score%2500 < 2000) {
		glColor3f(0.40, 0.40, 0.75); // Sunrise
	}
	else {
		glColor3f(0.40, 0.80, 0.75); // Day
	}

	glRecti(-100, 60, 20, 190);
	glRecti(0, 60, 100, 120);
	glRecti(110, 60, 180, 140);
	glRecti(180, 60, 250, 160);
	glRecti(260, 60, 310, 200);
	glRecti(320, 60, 360, 140);
	glRecti(360, 60, 420, 150);
	glRecti(420, 60, 480, 120);
	glRecti(490, 60, 540, 160); 
	glRecti(550, 60, 600, 180);
	glRecti(600, 60, 680, 150);
	glRecti(690, 60, 720, 200);
	glRecti(730, 60, 780, 150);
	glRecti(780, 60, 820, 120);
	glRecti(830, 60, 900, 190);

	glPopMatrix();


	// Culoarea pamant de jos
	if (score%2500 < 500) {
		glColor3f(0.86, 0.78, 0.66); // Day
	}
	else if (score%2500 >= 500 && score%2500 < 1000) {
		glColor3f(0.75, 0.60, 0.55); // Sundown
	}
	else if (score%2500 >= 1000 && score%2500 < 1500) {
		glColor3f(0.55, 0.50, 0.35); // Night
	}
	else if (score%2500 >= 1500 && score%2500 < 2000) {
		glColor3f(0.75, 0.60, 0.55); // Sunrise
	}
	else {
		glColor3f(0.86, 0.78, 0.66); // Day
	}

	glBegin(GL_POLYGON);
	glVertex2i(-50, -100);// Stanga jos
	glVertex2i(900, -100); // Dreapta jos
	glVertex2i(900, 60);  // Dreapta sus
	glVertex2i(-100, 60); // Stanga sus
	glEnd();


	// Delimitam soseaua de iarba partea de jos
	if (score%2500 < 500) {
		glColor3f(0.19, 0.78, 0.1); // Day
	}
	else if (score%2500 >= 500 && score%2500 < 1000) {
		glColor3f(0.15, 0.50, 0.1); // Sundown
	}
	else if (score%2500 >= 1000 && score%2500 < 1500) {
		glColor3f(0.10, 0.35, 0.05); // Night
	}
	else if (score%2500 >= 1500 && score%2500 < 2000) {
		glColor3f(0.15, 0.50, 0.1); // Sunrise
	}
	else {
		glColor3f(0.19, 0.78, 0.1); // Day
	}

	glBegin(GL_POLYGON);
	glVertex2i(-50, 20);// Stanga jos
	glVertex2i(900, 20); // Dreapta jos
	glVertex2i(900, 60);  // Dreapta sus
	glVertex2i(-100, 60); // Stanga sus
	glEnd();

	// Delimitare sosea
	//glColor3f(0.14, 0.6, 0.1); // verde inchis
	if (score%2500 < 500) {
		glColor3f(0.14, 0.6, 0.1); // Day
	}
	else if (score%2500 >= 500 && score%2500 < 1000) {
		glColor3f(0.1, 0.4, 0.1); // Sundown
	}
	else if (score%2500 >= 1000 && score%2500 < 1500) {
		glColor3f(0.05, 0.2, 0.05); // Night
	}
	else if (score%2500 >= 1500 && score%2500 < 2000) {
		glColor3f(0.1, 0.4, 0.1); // Sunrise
	}
	else {
		glColor3f(0.14, 0.6, 0.1); // Day
	}
	glPushMatrix();
	glRecti(-100, 50, 900, 60);
	glPopMatrix();

	// Delimitare meniu
	if (jocActiv == 0) {
		glColor3f(1.0, 1.0, 1.0);
		glPushMatrix();
		glRecti(250, 350, 560, 390);
		glRecti(250, 300, 560, 340);
		glRecti(250, 250, 560, 290);
		glPopMatrix();


		string highScoreStr = "HIGHSCORE:  " + to_string(highscore);
		glColor4f(0.0f, 0.0f, 0.0f, 0.0f);
		glRasterPos2f(300.0, 310.0);
		for (char c : highScoreStr) {
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
		}


		RenderString(340.0f, 360.0f, GLUT_BITMAP_TIMES_ROMAN_24, (const unsigned char*)"START GAME");
		//RenderString(280.0f, 310.0f, GLUT_BITMAP_TIMES_ROMAN_24, (const unsigned char*)"HIGHSCORE :"+highscore);
		RenderString(380.0f, 260.0f, GLUT_BITMAP_TIMES_ROMAN_24, (const unsigned char*)"EXIT");
	}
	else {
		// Incetineste jocul
		string ScoreStr = "Score: " + to_string(score);
		glColor4f(0.0f, 0.0f, 0.0f, 0.0f);
		glRasterPos2f(360.0, -20.0);
		for (char c : ScoreStr) {
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
		}
		
		// Desenam BIRD
		if (score%2500 >= 1000 && score%2500 < 1500)
			glColor3f(0.75, 0.7, 0.1); // Night
		else
			glColor3f(0.95, 0.9, 0.2);

		glPushMatrix();
		glTranslated(30.0, j, 0.0);
		//float grad = sin(((int)j % 120)*180/120)*45;
		if (j != 120 && j != 240 && j != 360 && j != 480 && j != 600)
			glRotated(grad*30.0f, 0, 0, 1);


		glBegin(GL_TRIANGLE_FAN);
		glVertex2f(0.0f, 0.0f); // Center vertex
		
		for (GLfloat angle = 0.0f; angle <= 2.0f * 3.14159f; angle += 0.02f) {
			GLfloat x = 30.0f * cos(angle);
			GLfloat y = 20.0f * sin(angle);
			glVertex2f(x, y);
		}
		glEnd();

		// coada
		glBegin(GL_TRIANGLES);
			glVertex2f(-40, 15);
			glVertex2f(-10, 20);
			glVertex2f(-10, -10);
		glEnd();

		// ochii
		glEnable(GL_POINT_SMOOTH);
		glPointSize(18.0f);
		glBegin(GL_POINTS);
			if (score%2500 >= 1000 && score%2500 < 1500)
				glColor3f(0.80, 0.80, 0.80); // Ni	ght
			else
				glColor3f(1.0, 1.0, 1.0);
			glVertex2f(20.0f, 7.0f);
		glEnd();

		glPointSize(5.0f);
		glBegin(GL_POINTS);
			glColor3f(0.0, 0.0, 0.0);
			glVertex2f(25.0f, 8.0f);
		glEnd();
		
		// ciocul
		if (score%2500 >= 1000 && score%2500 < 1500)
			glColor3f(0.7, 0.5, 0.15); // Night
		else
			glColor3f(0.9, 0.6, 0.3);
		glRecti(12, -12, 40, 0);

		// aripa
		if (score%2500 >= 1000 && score%2500 < 1500)
			glColor3f(0.70, 0.65, 0.1); // Night
		else
			glColor3f(0.90, 0.85, 0.1);
		glBegin(GL_TRIANGLES);
			glVertex2f(-25, 10);
			glVertex2f(5, 10);
			glVertex2f(-5, -5);
		glEnd();

		if (ok == 0)
		{
			rsj = 8;
			rss = -8;
			rdj = -8;
			rds = 8;
		}

		glPopMatrix();

		if (ok == 0) {
			glColor3f(1.0, 1.0, 1.0);
			glPushMatrix();
			glRecti(250, 350, 560, 390);
			glRecti(250, 300, 560, 340);
			glRecti(250, 250, 560, 290);
			glPopMatrix();
			RenderString(350.0f, 410.0f, GLUT_BITMAP_TIMES_ROMAN_24, (const unsigned char*)"BIRD DIED");
			RenderString(340.0f, 360.0f, GLUT_BITMAP_TIMES_ROMAN_24, (const unsigned char*)"TRY AGAIN");
			RenderString(320.0f, 310.0f, GLUT_BITMAP_TIMES_ROMAN_24, (const unsigned char*)"BACK TO MENU");
			RenderString(380.0f, 260.0f, GLUT_BITMAP_TIMES_ROMAN_24, (const unsigned char*)"EXIT");
		}

		// Viteza up-down player
		if (contor == 1 && (j != 600 && j != 480 && j != 360 && j != 240)) {
			j = j + 1;
		}
		else if (contor == 0.5 && (j != 600 && j != 480 && j != 360 && j != 120)) {
			j = j + 1;
		}
		else if (contor == -0.5 && (j != 600 && j != 360 && j != 240 && j != 120)) {
			j = j - 1;
		}
		else if (contor == -1 && (j != 480 && j != 360 && j != 240 && j != 120)) {
			j = j - 1;
		}
		else {
			contor = 0;
		}

		// desenam tevile verzi
		glPushMatrix();
		glTranslated(loc_vert, 0.0, 0.0);

		if (score%2500 < 500) {
			glColor3f(0.19, 0.78, 0.1); // Day
		}
		else if (score%2500 >= 500 && score%2500 < 1000) {
			glColor3f(0.15, 0.50, 0.1); // Sundown
		}
		else if (score%2500 >= 1000 && score%2500 < 1500) {
			glColor3f(0.10, 0.35, 0.05); // Night
		}
		else if (score%2500 >= 1500 && score%2500 < 2000) {
			glColor3f(0.15, 0.50, 0.1); // Sunrise
		}
		else {
			glColor3f(0.19, 0.78, 0.1); // Day
		}
		glRecti(0, height + 60, 80, 750);
		glRecti(0, 50, 80, height - 60);
		
		// margini verde inchis
		if (score%2500 < 500) {
			glColor3f(0.14, 0.6, 0.1); // Day
		}
		else if (score%2500 >= 500 && score%2500 < 1000) {
			glColor3f(0.1, 0.4, 0.1); // Sundown
		}
		else if (score%2500 >= 1000 && score%2500 < 1500) {
			glColor3f(0.05, 0.2, 0.05); // Night
		}
		else if (score%2500 >= 1500 && score%2500 < 2000) {
			glColor3f(0.1, 0.4, 0.1); // Sunrise
		}
		else {
			glColor3f(0.14, 0.6, 0.1); // Day
		}
		glRecti(-10, height + 60, 90, height + 70);
		glRecti(-10, height - 70, 90, height - 60);

		glPopMatrix();
	}

	//START
	startgame();
	glutPostRedisplay();
	glutSwapBuffers();
	glFlush();
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-50.0, 850.0, -100.0, 650.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void miscasus(void)
{
	if (ok != 0)
	{
		if (j < 600)
		{
			contor = 1;
			j += 1;
			grad = 1;
		}
		PlaySound(TEXT("flap.wav"), NULL, SND_ASYNC);
		glutPostRedisplay();
	}
}

void miscajos(void)
{
	if (ok != 0)
	{
		if (j > 120)
		{
			contor = -1;
			j -= 1;
			grad = -1;
		}
		PlaySound(TEXT("flap.wav"), NULL, SND_ASYNC);
		glutPostRedisplay();
	}
}

void keyboard(int key, int x, int y)
{
	switch (key) {
	case GLUT_KEY_UP:
		jocActiv = 1;
		miscasus();
		break;
	case GLUT_KEY_DOWN:
		jocActiv = 1;
		miscajos();
		break;
	}
}

void mouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		if (x > 250 && x < 560) {
			if (y > 250 && y < 290) {
				jocActiv = 1;
				loc_vert = 1000;
				timp = 0.3;
				timp_nori = 0.2;
				score = 0;
				ok = 1;
			}
			else if (y > 300 && y < 340) {
				jocActiv=0;
			}
			else if (y > 350 && y < 390) {
				file.close();
				exit(0);
			}
		}
	}
}

int main(int argc, char** argv)
{
	if (readOnce == 0)
		if (getline(file, s)) {
			highscore = stoi(s);
			cout << s;
			readOnce = 1;
		}
		else {
			highscore = 0;
		}


	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(900, 700);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("Flappy Bird - mini game");
	
	init();
	glutDisplayFunc(drawScene);
	glutReshapeFunc(reshape);
	glutSpecialFunc(keyboard);
	glutMouseFunc(mouse);

	glutMainLoop();
}
