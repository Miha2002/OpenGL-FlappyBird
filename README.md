# OpenGL-FlappyBird


Pe scurt am încercat să recreăm jocul Flappy Bird. Pasărea noastră se poate deplasa pe 5 linii, trebuie să se ferească de țevi, iar pentru fiecare țeavă evitată primește puncte.
Am implementat un ciclu zi/noapte în funcție de scorul pe care îl atingi și am adăugat mai mulți nori care sunt generați în mod aleator și au o viteza diferită față de restul elementelor.
Pe lângă acestea, am adăugat și un sistem de memorare a unui highscore precum și sunete la mișcarea păsării, la obținerea unui punct și la sfârșitul jocului.
Pentru realizarea proiectului am folosit următoarele:
•	GL_TRIANGLE_FAN pentru a obține corpul păsării, GL_TRIANGLES, GL_POINTS,glRecti() pentru a desena detaliile păsării ( aripi, coadă, ochii și cioc ).
•	glRecti() pentru a realiza țevile, norii, clădirile din fundal și pământul.
•	Folosim glTranslated() pentru a repoziționa obiecte pe axa verticală.
•	Împreună cu glTranslated() am utilizat glRotated() pentru am simula mișcarea de sus/jos a păsării.
•	Am adăugat funcția de mouse() pe care o utilizăm în accesarea meniului.
•	Highscore-ul este memorat într-un fișier, acesta este accesat simultan cu meniul, iar la finalul jocului dacă scorul obținut este mai mare înlocuim highscore-ul din fișier cu scorul obținut.
