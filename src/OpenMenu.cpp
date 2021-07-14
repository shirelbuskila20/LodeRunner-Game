#include"OpenMenu.h"
//--------------------------------------------------------------------------------------------
//c-tor
OpenMenu::OpenMenu()
{
	m_sprite.setPosition({ 0,0 });
	m_sprite.setTexture((*ResourcesManage::instance().getPtrToTexture(openMenu_b)));
}

//--------------------------------------------------------------------------------------------
//הפונקציה יוצרת חלון
void OpenMenu::run()
{
	auto window = sf::RenderWindow({ WINDOW_WIDTH,WINDOW_HEIGHT }, "Lode Runner");
	menu(window);
}

//--------------------------------------------------------------------------------------------
//הפונקציה מדפיסה רקע למסף פתיחה ומטפלת בלחיצה על הכפתורים
void OpenMenu::menu(sf::RenderWindow& window)
{
	window.clear();
	window.draw(m_sprite);
	window.display();

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				exit(0);
				break;
			case sf::Event::MouseButtonReleased:
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					Buttons button = getMenuButton(sf::Vector2f(event.mouseButton.x, event.mouseButton.y));
					switch (button)
					{
					case start_button:  //כפתור כניסה

						if (m_controller.run(window))//אם הוא ניצח
						{
						
							window.clear();
							//מדפיס מסך WIN
							m_sprite.setTexture((*ResourcesManage::instance().getPtrToTexture(win_b)));
							m_sound.setBuffer((*ResourcesManage::instance().getPtrToMusic(winMusic_m)));
							m_sound.play();
							window.draw(m_sprite);
							window.display();
						}
						else//אם הפסיד
						{
							//מדפיס מסך GAME OVER
							window.clear();
							m_sprite.setTexture((*ResourcesManage::instance().getPtrToTexture(gameOver_b)));
							m_sound.setBuffer((*ResourcesManage::instance().getPtrToMusic(gameOverMusic_m)));
							m_sound.play();
							window.draw(m_sprite);
							window.display();
						}
						break;
					case end_button://כפתור יציאה
						window.close(); 
						exit(0);
						break;

					default:
						break;
					}
				}
				break;
			}
		}
	}
}

//--------------------------------------------------------------------------------------------
// הפונקציה מחזירה את הכפתור שנלחץ לפי המיקום
Buttons OpenMenu::getMenuButton(sf::Vector2f buttonPos)
{
	if (buttonPos.x > 284 && buttonPos.x < 544
		&& buttonPos.y > 297 && buttonPos.y < 372)
		return start_button;

	else if (buttonPos.x > 284 && buttonPos.x < 544
		&& buttonPos.y > 395 && buttonPos.y < 470)
		return end_button;
}