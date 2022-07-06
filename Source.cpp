#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <list>

using namespace sf;

bool MouseTouch(int Mx, int My, Sprite baloon) {
	int BaloonPosX = baloon.getPosition().x;
	int BaloonPosY = baloon.getPosition().y;
	int baloonSizeX = 207;
	int baloonSizeY = 535;

	if (Mx > BaloonPosX && Mx < BaloonPosX + baloonSizeX)
		if (My > BaloonPosY && My < BaloonPosY + (baloonSizeY/2 + 30))
			return true;
		else return false;
	else return false;
}

Sprite animPop(Sprite baloon, Sprite baloonpop) {
	int baloonPosX = baloon.getPosition().x;
	int baloonPosY = baloon.getPosition().y;

	baloonpop.setPosition(baloonPosX - 22,baloonPosY);
	return baloonpop;
}

Sprite StartPosition(Sprite baloon) {
	int screenX = GetSystemMetrics(SM_CXSCREEN);
	int screenY = GetSystemMetrics(SM_CYSCREEN);
	int pictureSizeX = 207;
	int pictureSizeY = 535;
	int posX = rand() % (screenX - pictureSizeX);
	int posY = screenY / 2 + pictureSizeY + rand() % 950 + 10;
	baloon.setPosition(posX, posY);
	return baloon;
}

Sprite BirdStartPosition(Sprite bird) {
	int screenY = GetSystemMetrics(SM_CYSCREEN);
	int pictureSizeY = 460;
	int PosX = -500;
	int PosY = 80 + (rand() % (screenY - 200));
	bird.setPosition(PosX, PosY);
	return bird;
}

Sprite CloudStartPosition(Sprite cloud) {
	int screenX = GetSystemMetrics(SM_CXSCREEN);
	int screenY = GetSystemMetrics(SM_CYSCREEN);
	int pictureSizeY = 460;
	int PosX = screenX + 500 + rand() % 500;
	int PosY = 80 + (rand() % (screenY - 200));
	cloud.setPosition(PosX, PosY);
	return cloud;
}

int main() {
	srand(time(0));
	float Moveframe = 0;
	float Popframe1 = 0;
	float Popframe2 = 0;
	float Popframe3 = 0;
	float Popframe4 = 0;
	float Popframe5 = 0;
	float Popframe6 = 0;
	float Popframe7 = 0;
	float BirdFrame = 0;
	float CloudFrame = 0;
	float PopAnimSpeed = 0.9f;
	float MoveAnimSpeed = 0.09f;
	float BirdAnimSpeed = 0.05f;
	float CloudAnimSpeed = 0.05f;
	int speed = 3;
	int birdspeed = 2;
	int cloudspeed = 1;
	float birdsize = 0.35f;
	float cloudsize = 0.5f;
	int screenX = GetSystemMetrics(SM_CXSCREEN);
	int screenY = GetSystemMetrics(SM_CYSCREEN);
	bool PopAnimFlag1 = false;
	bool PopAnimFlag2 = false;
	bool PopAnimFlag3 = false;
	bool PopAnimFlag4 = false;
	bool PopAnimFlag5 = false;
	bool PopAnimFlag6 = false;
	bool PopAnimFlag7 = false;
	RenderWindow window (VideoMode(screenX, screenY), "Baloons!", Style::Fullscreen);
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60);
	Texture RedMove;
	Texture RedPop;
	Texture bird;
	Texture cloud;
	RedMove.loadFromFile("sprites/RedSpriteSheet.png");
	RedPop.loadFromFile("sprites/RedPopSpriteSheet.png");
	bird.loadFromFile("sprites/birdSpritesheet.png");
	cloud.loadFromFile("sprites/CloudSpritesheet.png");
	//Объекты шариков
	int pictureSizeX = 207;
	int pictureSizeY = 535;
	Sprite baloon1(RedMove);
	Sprite baloon2(RedMove);
	Sprite baloon3(RedMove);
	Sprite baloon4(RedMove);
	Sprite baloon5(RedMove);
	Sprite baloon6(RedMove);
	Sprite baloon7(RedMove);
	//Объекты при лопании
	Sprite baloon1pop(RedPop);
	Sprite baloon2pop(RedPop);
	Sprite baloon3pop(RedPop);
	Sprite baloon4pop(RedPop);
	Sprite baloon5pop(RedPop);
	Sprite baloon6pop(RedPop);
	Sprite baloon7pop(RedPop);
	//Птицы
	Sprite bird1(bird);
	Sprite bird2(bird);
	Sprite bird3(bird);
	Sprite bird4(bird);
	//Облака
	Sprite cloud1(cloud);
	Sprite cloud2(cloud);
	Sprite cloud3(cloud);
	//Нарезка спрайтшитов
	baloon1.setTextureRect(IntRect(0, 0, 207,535));
	baloon2.setTextureRect(IntRect(0, 0, 207, 535));
	baloon3.setTextureRect(IntRect(0, 0, 207, 535));
	baloon4.setTextureRect(IntRect(0, 0, 207, 535));
	baloon5.setTextureRect(IntRect(0, 0, 207, 535));
	baloon6.setTextureRect(IntRect(0, 0, 207, 535));
	baloon7.setTextureRect(IntRect(0, 0, 207, 535));

	baloon1pop.setTextureRect(IntRect(0, 0, 250, 535));
	baloon2pop.setTextureRect(IntRect(0, 0, 250, 535));
	baloon3pop.setTextureRect(IntRect(0, 0, 250, 535));
	baloon4pop.setTextureRect(IntRect(0, 0, 250, 535));
	baloon5pop.setTextureRect(IntRect(0, 0, 250, 535));
	baloon6pop.setTextureRect(IntRect(0, 0, 250, 535));
	baloon7pop.setTextureRect(IntRect(0, 0, 250, 535));

	bird1.setTextureRect(IntRect(0, 0, 600, 460));
	bird2.setTextureRect(IntRect(0, 0, 600, 460));
	bird3.setTextureRect(IntRect(0, 0, 600, 460));
	bird4.setTextureRect(IntRect(0, 0, 600, 460));

	cloud1.setTextureRect(IntRect(0, 0, 550, 360));
	cloud2.setTextureRect(IntRect(0, 0, 550, 360));
	cloud3.setTextureRect(IntRect(0, 0, 550, 360));
	//Начальная позиция
	baloon1 = StartPosition(baloon1);
	baloon2 = StartPosition(baloon2);
	baloon3 = StartPosition(baloon3);
	baloon4 = StartPosition(baloon4);
	baloon5 = StartPosition(baloon5);
	baloon6 = StartPosition(baloon6);
	baloon7 = StartPosition(baloon7);

	baloon1pop = StartPosition(baloon1pop);
	baloon2pop = StartPosition(baloon2pop);
	baloon3pop = StartPosition(baloon3pop);
	baloon4pop = StartPosition(baloon4pop);
	baloon5pop = StartPosition(baloon5pop);
	baloon6pop = StartPosition(baloon6pop);
	baloon7pop = StartPosition(baloon7pop);

	bird1 = BirdStartPosition(bird1);
	bird2.setPosition(bird1.getPosition().x - 100, bird1.getPosition().y - 80);
	bird3.setPosition(bird1.getPosition().x - 100, bird1.getPosition().y + 80);
	bird4.setPosition(bird1.getPosition().x - 200, bird1.getPosition().y + 150);

	cloud1 = CloudStartPosition(cloud1);
	cloud2 = CloudStartPosition(cloud2);
	cloud3 = CloudStartPosition(cloud3);
	//Размер
	bird1.setScale(birdsize, birdsize);
	bird2.setScale(birdsize, birdsize);
	bird3.setScale(birdsize, birdsize);
	bird4.setScale(birdsize, birdsize);

	cloud1.setScale(cloudsize, cloudsize);
	cloud2.setScale(cloudsize, cloudsize);
	cloud3.setScale(cloudsize, cloudsize);
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		//Анимация
		Moveframe += MoveAnimSpeed;
		if (Moveframe > 4)
			Moveframe -= 4;
		baloon1.setTextureRect(IntRect(207 * int(Moveframe), 0, 207, 535));
		baloon2.setTextureRect(IntRect(207 * int(Moveframe), 0, 207, 535));
		baloon3.setTextureRect(IntRect(207 * int(Moveframe), 0, 207, 535));
		baloon4.setTextureRect(IntRect(207 * int(Moveframe), 0, 207, 535));
		baloon5.setTextureRect(IntRect(207 * int(Moveframe), 0, 207, 535));
		baloon6.setTextureRect(IntRect(207 * int(Moveframe), 0, 207, 535));
		baloon7.setTextureRect(IntRect(207 * int(Moveframe), 0, 207, 535));

		if (PopAnimFlag1) {
			Popframe1 += PopAnimSpeed;
			if (Popframe1 > 8) {
				Popframe1 -= 8;
				PopAnimFlag1 = false;
				baloon1pop = StartPosition(baloon1pop);
			}
			baloon1pop.setTextureRect(IntRect(250 * int(Popframe1), 0, 250, 535));
		}

		if (PopAnimFlag2) {
			Popframe2 += PopAnimSpeed;
			if (Popframe2 > 8) {
				Popframe2 -= 8;
				PopAnimFlag2 = false;
				baloon2pop = StartPosition(baloon2pop);
			}
			baloon2pop.setTextureRect(IntRect(250 * int(Popframe2), 0, 250, 535));
		}

		if (PopAnimFlag3) {
			Popframe3 += PopAnimSpeed;
			if (Popframe3 > 8) {
				Popframe3 -= 8;
				PopAnimFlag3 = false;
				baloon3pop = StartPosition(baloon3pop);
			}
			baloon3pop.setTextureRect(IntRect(250 * int(Popframe3), 0, 250, 535));
		}

		if (PopAnimFlag4) {
			Popframe4 += PopAnimSpeed;
			if (Popframe4 > 8) {
				Popframe4 -= 8;
				PopAnimFlag4 = false;
				baloon4pop = StartPosition(baloon4pop);
			}
			baloon4pop.setTextureRect(IntRect(250 * int(Popframe4), 0, 250, 535));
		}

		if (PopAnimFlag5) {
			Popframe5 += PopAnimSpeed;
			if (Popframe5 > 8) {
				Popframe5 -= 8;
				PopAnimFlag5 = false;
				baloon5pop = StartPosition(baloon5pop);
			}
			baloon5pop.setTextureRect(IntRect(250 * int(Popframe5), 0, 250, 535));
		}

		if (PopAnimFlag6) {
			Popframe6 += PopAnimSpeed;
			if (Popframe6 > 8) {
				Popframe6 -= 8;
				PopAnimFlag6 = false;
				baloon6pop = StartPosition(baloon6pop);
			}
			baloon6pop.setTextureRect(IntRect(250 * int(Popframe6), 0, 250, 535));
		}

		if (PopAnimFlag7) {
			Popframe7 += PopAnimSpeed;
			if (Popframe7 > 8) {
				Popframe7 -= 8;
				PopAnimFlag7 = false;
				baloon7pop = StartPosition(baloon7pop);
			}
			baloon7pop.setTextureRect(IntRect(250 * int(Popframe7), 0, 250, 535));
		}

		BirdFrame += BirdAnimSpeed;
		if (Moveframe > 4)
			Moveframe -= 4;

		bird1.setTextureRect(IntRect(600 * int(Moveframe), 0, 600, 460));
		bird2.setTextureRect(IntRect(600 * int(Moveframe), 0, 600, 460));
		bird3.setTextureRect(IntRect(600 * int(Moveframe), 0, 600, 460));
		bird4.setTextureRect(IntRect(600 * int(Moveframe), 0, 600, 460));

		CloudFrame += CloudAnimSpeed;
		if (CloudFrame > 4)
			CloudFrame -= 4;

		cloud1.setTextureRect(IntRect(550 * int(Moveframe), 0, 550, 360));
		cloud2.setTextureRect(IntRect(550 * int(Moveframe), 0, 550, 360));
		cloud3.setTextureRect(IntRect(550 * int(Moveframe), 0, 550, 360));

		//Смещение
		baloon1.setPosition(baloon1.getPosition().x, baloon1.getPosition().y - speed);
		baloon2.setPosition(baloon2.getPosition().x, baloon2.getPosition().y - speed);
		baloon3.setPosition(baloon3.getPosition().x, baloon3.getPosition().y - speed);
		baloon4.setPosition(baloon4.getPosition().x, baloon4.getPosition().y - speed);
		baloon5.setPosition(baloon5.getPosition().x, baloon5.getPosition().y - speed);
		baloon6.setPosition(baloon6.getPosition().x, baloon6.getPosition().y - speed);
		baloon7.setPosition(baloon7.getPosition().x, baloon7.getPosition().y - speed);

		bird1.setPosition(bird1.getPosition().x + birdspeed, bird1.getPosition().y);
		bird2.setPosition(bird2.getPosition().x + birdspeed, bird2.getPosition().y);
		bird3.setPosition(bird3.getPosition().x + birdspeed, bird3.getPosition().y);
		bird4.setPosition(bird4.getPosition().x + birdspeed, bird4.getPosition().y);

		cloud1.setPosition(cloud1.getPosition().x - cloudspeed, cloud1.getPosition().y);
		cloud2.setPosition(cloud2.getPosition().x - cloudspeed, cloud2.getPosition().y);
		cloud3.setPosition(cloud3.getPosition().x - cloudspeed, cloud3.getPosition().y);
		//Возвращение
		if (baloon1.getPosition().y < 0 - pictureSizeY) {
			baloon1 = StartPosition(baloon1);
		} else if (baloon2.getPosition().y < 0 - pictureSizeY) {
			baloon2 = StartPosition(baloon2);
		} else if (baloon3.getPosition().y < 0 - pictureSizeY) {
			baloon3 = StartPosition(baloon3);
		} else if (baloon4.getPosition().y < 0 - pictureSizeY) {
			baloon4 = StartPosition(baloon4);
		} else if (baloon5.getPosition().y < 0 - pictureSizeY) {
			baloon5 = StartPosition(baloon5);
		}else if (baloon6.getPosition().y < 0 - pictureSizeY) {
			baloon6 = StartPosition(baloon6);
		}else if (baloon7.getPosition().y < 0 - pictureSizeY) {
			baloon7 = StartPosition(baloon7);
		}

		if (bird1.getPosition().x > screenX + pictureSizeX + 50) {
			bird1 = BirdStartPosition(bird1);
			bird2.setPosition(bird1.getPosition().x - 100, bird1.getPosition().y - 80);
			bird3.setPosition(bird1.getPosition().x - 100, bird1.getPosition().y + 80);
			bird4.setPosition(bird1.getPosition().x - 200, bird1.getPosition().y + 150);
		}

		if (cloud1.getPosition().x < - 500) {
			cloud1 = CloudStartPosition(cloud1);	
		}else if (cloud2.getPosition().x < - 500) {
			cloud2 = CloudStartPosition(cloud2);
		}else if (cloud3.getPosition().x < - 500) {
			cloud3 = CloudStartPosition(cloud3);
		}
		//Нажатие
		if (event.type == Event::MouseButtonPressed && event.key.code == Mouse::Left) {
			int MouseX = Mouse::getPosition().x;
			int MouseY = Mouse::getPosition().y;

			if (MouseTouch(MouseX, MouseY, baloon1)) {
				PopAnimFlag1 = true;
				baloon1pop = animPop(baloon1, baloon1pop);
				baloon1 = StartPosition(baloon1);
			}
			else if (MouseTouch(MouseX, MouseY, baloon2)) {
				PopAnimFlag2 = true;
				baloon2pop = animPop(baloon2, baloon2pop);
				baloon2 = StartPosition(baloon2);
			}
			else if (MouseTouch(MouseX, MouseY, baloon3)) {
				PopAnimFlag3 = true;
				baloon3pop = animPop(baloon3, baloon3pop);
				baloon3 = StartPosition(baloon3);
			}
			else if (MouseTouch(MouseX, MouseY, baloon4)) {
				PopAnimFlag4 = true;
				baloon4pop = animPop(baloon4, baloon4pop);
				baloon4 = StartPosition(baloon4);
			}
			else if (MouseTouch(MouseX, MouseY, baloon5)) {
				PopAnimFlag5 = true;
				baloon5pop = animPop(baloon5, baloon5pop);
				baloon5 = StartPosition(baloon5);
			}
			else if (MouseTouch(MouseX, MouseY, baloon6)) {
				PopAnimFlag6 = true;
				baloon6pop = animPop(baloon6, baloon6pop);
				baloon6 = StartPosition(baloon6);
			}
			else if (MouseTouch(MouseX, MouseY, baloon7)) {
				PopAnimFlag7 = true;
				baloon7pop = animPop(baloon7, baloon7pop);
				baloon7 = StartPosition(baloon7);
			}
		}
		//Отрисовка
		window.clear(Color(66,170,255));
		window.draw(bird1);
		window.draw(bird2);
		window.draw(bird3);
		window.draw(bird4);
		window.draw(cloud1);
		window.draw(cloud2);
		window.draw(cloud3);
		window.draw(baloon1);
		window.draw(baloon2);
		window.draw(baloon3);
		window.draw(baloon4);
		window.draw(baloon5);
		window.draw(baloon6);
		window.draw(baloon7);
		window.draw(baloon1pop);
		window.draw(baloon2pop);
		window.draw(baloon3pop);
		window.draw(baloon4pop);
		window.draw(baloon5pop);
		window.draw(baloon6pop);
		window.draw(baloon7pop);
		window.display();
	}
	return 0;
}