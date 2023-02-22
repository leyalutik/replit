#include <vector>
#include <map>
#include <set>
#include<exception>
#include <cassert>
#include<cstdlib>
#include<iostream>
#include<string>
#include <sstream>
#include <fstream>
#include <chrono>

#include "lessons.h"
#include "bricks.h"
#include "edit.h"
#include "working_space.h"
#include "interface.h"

LESSONS::LESSONS(const int32_t number_lessons_new)
{
	LESSONS::number_lessons = number_lessons_new;
	LESSONS::ws.initialize();

}


LESSONS::LESSONS(
		const int32_t number_lessons_new,
		const std::string& OS_new,
		const std::string& browser_command_new
		)
{

	LESSONS::number_lessons = number_lessons_new;
	LESSONS::ws.OS = OS_new;
	LESSONS::ws.browser_command = browser_command_new;
}
void LESSONS::display_main_menu()
{
std::string text_menu = "";

	text_menu += scroll_down(4)
				+ right_shift(5) 
				+ std::string ("{{{ Main Меню }}}")
				+ scroll_down(2);


	text_menu += right_shift(4) 
		+ std::string("Неделя 1.") 
		+ right_shift(4) + std::to_string(1)
		+ scroll_down(1);

	text_menu += right_shift(4) 
		+ std::string("Неделя 2.") 
		+ right_shift(4) + std::to_string(2)
		+ scroll_down(1);
	text_menu += right_shift(4) 
		+ std::string("Неделя 3.") 
		+ right_shift(4) + std::to_string(3)
		+ scroll_down(1);

	text_menu += right_shift(4) 
		+ std::string("Неделя 4.") 
		+ right_shift(4) + std::to_string(4)
		+ scroll_down(1);

	text_menu += right_shift(4) 
		+ std::string("Выход.") 
		+ right_shift(5) + std::to_string(5)
		+ scroll_down(1);

	display_text_in_page(text_menu,0,0,(4+5));



}
void LESSONS::display_menu()
{
	std::string text_menu = "";

	text_menu += scroll_down(4)
				+ right_shift(5) 
				+ std::string ("{{{ Меню }}}")
				+ scroll_down(2);


	text_menu += right_shift(4) 
		+ std::string("Следующий урок.") 
		+ right_shift(5) + std::to_string(1)
		+ scroll_down(1);

	text_menu += right_shift(4) 
		+ std::string("Повторить урок.") 
		+ right_shift(5) + std::to_string(2)
		+ scroll_down(1);
	text_menu += right_shift(4) 
		+ std::string("Предыдущий урок.") 
		+ right_shift(4) + std::to_string(3)
		+ scroll_down(1);

	text_menu += right_shift(4) 
		+ std::string("Выбрать номер урока.") 
		+ right_shift(4) + std::to_string(4)
		+ scroll_down(1);

	text_menu += right_shift(4) 
		+ std::string("Выход.") 
		+ right_shift(6) + std::to_string(5)
		+ scroll_down(1);

	display_text_in_page(text_menu,0,0,(4+5));




}
void LESSONS::base_main_function(const int32_t i)
{
	switch(i)
	{
		case 1: LESSONS::start(0,15);
			std::getchar();
			break;
		case 2: display_text_in_page("Week 2 is developing",4,8,0);
			std::getchar();
			break;
		case 3: display_text_in_page("Week 2 is developing",4,8,0);
			std::getchar();
			break;
		case 4: display_text_in_page("Week 2 is developing",4,8,0);
			std::getchar();
			break;
	}

}

void LESSONS::start_program()
{
	int32_t i=0;
	int32_t number_options = 5;
	while(i< number_options)
	{
		LESSONS::display_main_menu();
		input(i);
		std::getchar();
		base_main_function(i);
	}

}
void LESSONS::menu()
{
	display_menu();
	int32_t i = 0;
	input(i);
	std::getchar();
	LESSONS::base_function(i);

}

void LESSONS::start(const int32_t start_new, const int32_t end_new)
{
	LESSONS::START_LESSON = start_new;
	LESSONS::END_LESSON = end_new;
	LESSONS::current_number = LESSONS::START_LESSON;
	while( LESSONS::current_number < LESSONS::END_LESSON 
			&& LESSONS::current_number >= LESSONS::START_LESSON)
	{
		LESSONS::flow(LESSONS::current_number);
		LESSONS::menu(); //change attribute current number
		
	}



}
void LESSONS::check(int32_t i)//positive i
{
	if(i<0)
	{
		throw std::runtime_error("Illegal input in function flow_lessons");
	}

}
void LESSONS::base_function(const int32_t i) //change attribute current_number
{
	LESSONS::check(i);	
	switch(i)
	{
		case 1://NEXT

			{
				if(LESSONS::current_number < LESSONS::END_LESSON)
				{
					++LESSONS::current_number;
				}
				else
				{
					display_text_in_page("It's a last lesson.",4,8,0);
					std::getchar();
				}
			}

			break;

		case 2: break;//REPEAT

		case 3:	{
				if(LESSONS::current_number > LESSONS::START_LESSON)
				{
					--LESSONS::current_number;
				}
				else
				{
					display_text_in_page("It's a first lesson.",4,8,0);
					std::getchar();	
				}
			}
			break;
		case 4:
			{
				display_text_in_page(
						std::string("Enter the number of lesson in span [") 
						+ std::to_string(LESSONS::START_LESSON) 
						+ std::string(",")
						+ std::to_string(LESSONS::END_LESSON)
						+ std::string(") :\n")
						,4,8,1);
				input(LESSONS::current_number);
				std::getchar();

			}
			break;

		case 5:	LESSONS::current_number = LESSONS::END_LESSON+1;
			break;

		default:break;
	}
}

void LESSONS::flow(int32_t i)
{
	check(i);

	switch(i)
	{

		case 0:
			LESSONS::display_preparations();
			LESSONS::lesson0();
			break;

		case 1: 
			LESSONS::lesson1();
			break;
		case 2: 
			LESSONS::lesson2();
			break;

		case 3: 
			LESSONS::lesson3();
			break;
		case 4:
			LESSONS::lesson4();
			break;
		case 5:
			LESSONS::lesson5();
			break;
		case 6:
			LESSONS::lesson6();
			break;
		case 7:
			LESSONS::lesson7();
			break;
		case 8:
			LESSONS::lesson8();
			break;
		case 9:
			LESSONS::lesson9();
			break;
		case 10:
			LESSONS::lesson10();
			break;
		case 11:
			LESSONS::lesson11();
			break;
		case 12:
			LESSONS::lesson12();
			break;


		default:
			display_text_in_page("Enter an other number option.",4,8,0);
			std::getchar();
			break;

	}

	

}
//DISPLAY PREPARATIONS
//------------------------------------------------------------------------------
void LESSONS::display_preparations()
{
	display_text_in_page((std::string("Подготовка к Скорочтению:\n\n") 
				+ right_shift(4) + std::string("Откройте программу Скорочтение.\n")
				+ right_shift(4) + std::string("Приготовьте журнал Наука и Жизнь.\n")
				+ right_shift(4) + std::string("Откройте сайты для чтения маленьких заметок.\n")
			     ),4,4,6);
	std::getchar();

}

//LESSON 0
//----------------------------------------------------------------------------

void LESSONS::lesson0()
{


	display_text_in_page((std::string("Task 0\n\n") 
				+ right_shift(4) + std::string("Упражнения по концентрации и расширению сферы зрения.\n")
				+ right_shift(4) + std::string("Подготовка:\n")
				+ right_shift(5) + std::string("Программа Скорочтение:\n")
				+ right_shift(6) + std::string("Тренажёр >> Нейронный ускоритель.\n")
				+ right_shift(5) + std::string("Таймер - 5 минут.\n")
				+ right_shift(4) + std::string("Описание задания:\n")
				+ right_shift(5) + std::string("Открыть программу.\n\n")

				+ right_shift(4) + std::string("1.Техника Мандарина\n")
				+ right_shift(4) + std::string("2.С Богом!\n")
			     ),7,3,11);
	std::getchar();


	display_text_in_page((std::string("Упражнение 0 завершено.\n\n")
				+ right_shift(4) + std::string(" У вас всё получилось!\n")
				+ right_shift(4) + std::string("        Молодец!\n")
			     ),4,8,4);
	std::getchar();
}

void LESSONS::lesson1()
{
	display_text_in_page((std::string("Task 1\n\n") 
				+ right_shift(4) + std::string("Чтение и подсчёт слов.\n")
				+ right_shift(4) + std::string("Подготовка:\n")
				+ right_shift(5) + std::string("Текст с лёгким содержанием.\n")
				+ right_shift(5) + std::string("Таймер - 5 минут.\n")
				+ right_shift(4) + std::string("Описание задания:\n")
				+ right_shift(5) + std::string("Прочитать текст с одновременным подсчётом слов.\n\n")
				
				+ right_shift(4) + std::string("1.Техника Мандарина\n")
				+ right_shift(4) + std::string("2.Начали!\n")
			     ),7,3,11);


	
	std::getchar();
	int32_t answer = 1;
	display_text_in_page("Установить таймер?\n\t\t\t\tYes(1)/No(2)",4,8,1);
	
	input(answer);
	std::getchar();
	if(answer == 1)
	{
		display_text_in_page("Input seconds:",4,8,0);	

		int32_t seconds=1;
		input(seconds);
		run_timer(seconds); //seconds

	}
	display_text_in_page(
			(std::string("Упражнение 1 завершено.\n\n")
			+ right_shift(4) + std::string(" У вас всё получилось!\n")
			+ right_shift(4) + std::string("        Молодец!\n")
		     ),4,8,4);

	std::getchar();



}


void LESSONS::lesson2()
{
	display_text_in_page((std::string("Task 2\n\n") 
				+ std::string("\t\t\t\tЧтение столбиков с шаблоном.\n")
				+ right_shift(4) + std::string("Подготовка:\n")
				+ right_shift(5) + std::string("Текст столбиком.\n")
				+ right_shift(5) + std::string("Таймер - 5 минут.\n")
				+ right_shift(4) + std::string("Описание задания:\n")
				+ right_shift(5) + std::string("Cдвигать шаблон сверху вниз\n")
				+ right_shift(6) + std::string("со скоростью одна секунда на колонку.\n")
				+ right_shift(5) + std::string("Через прорез шаблона нужно \"схватить,узнать\"\n")
				+ right_shift(6) + std::string("слова без прочитывания.\n\n")
				+ right_shift(4) + std::string("1.Техника Мандарина\n")
				+ right_shift(4) + std::string("2.Начали!\n")
			     ),7,3,13);
	std::getchar();

	display_text_in_page("Установить таймер?\n\t\t\t\tYes(1)/No(2)",4,8,1);
	
	int32_t answer = 1;	
	input(answer);
	std::getchar();
	if(answer == 1)
	{
		display_text_in_page("Input seconds:",4,8,0);	

		int32_t seconds=1;
		input(seconds);
		run_timer(seconds); //seconds

	}

	display_text_in_page(
			(std::string("Упражнение 2 завершено.\n\n")
			+ right_shift(4) + std::string(" У вас всё получилось!\n")
			+ right_shift(4) + std::string("        Молодец!\n")
		     ),4,8,4);

	std::getchar();
}

					
void LESSONS::lesson3()
{
	display_text_in_page((std::string("Task 3\n\n") 
				+ std::string("\t\t\t\tЧтение орфографического словаря.\n")
				+ right_shift(4) + std::string("Подготовка:\n")
				+ right_shift(5) + std::string("Сайт https://povto.ru/books/slovari/orfograficheskiy-slovar-online\n")
				+ right_shift(5) + std::string("Время 10-15 страниц.\n")
				+ right_shift(4) + std::string("Описание задания:\n")
				+ right_shift(5) + std::string("Просматривать колонку слов,\n")
				+ right_shift(6) + std::string("слова узнаются, но не проговариваются.\n")
				+ right_shift(5) + std::string("По 2 секунды на страницу.\n\n")
				+ right_shift(4) + std::string("Техника Мандарина\n")
				+ right_shift(4) + std::string("Полетели!\n")
			     ),7,3,13);

	std::getchar();	

	display_text_in_page("Запустить сайт?\n\t\t\t\tYes(1)/No(2)",4,8,1);

	int32_t answer = 1;
	input(answer);
	std::getchar();
	if(answer == 1)
	{
		LESSONS::ws.run_site("https://povto.ru/books/slovari/orfograficheskiy-slovar-online/orfograficheskii-slovar-online-bukva-a.htm");

		std::getchar();

	}

	
	display_text_in_page((std::string("Упражнение 3 завершено.\n\n")
				+ right_shift(4) + std::string(" У вас всё получилось!\n")
				+ right_shift(4) + std::string("        Молодец!\n")
			     ),4,8,4);

	std::getchar();

	
}

void  LESSONS::lesson4()
{


	display_text_in_page((std::string("Task 4\n\n") 
				+ right_shift(4) + std::string("\"Поле зрения\" (расширение сферического зрения)\n")
				+ right_shift(4) + std::string("Подготовка:\n")
				+ right_shift(5) + std::string("Время - 3 раза.\n")
				+ right_shift(4) + std::string("Описание задания:\n")
				+ right_shift(5) + std::string("Запускайте программу.\n\n")
				+ right_shift(4) + std::string("Техника Мандарина\n")
				+ right_shift(4) + std::string("Полетели!\n")
			     ),7,3,10);

	std::getchar();	


	display_text_in_page((std::string("Упражнение 4 завершено.\n\n")
				+ right_shift(4) + std::string(" У вас всё получилось!\n")
				+ right_shift(4) + std::string("        Молодец!\n")
			     ),4,8,4);

	std::getchar();
}

void  LESSONS::lesson5()
{
	
	display_text_in_page((std::string("Task 5\n\n") 
				+ right_shift(4) + std::string("Прочтите маленькую колонку и выделите главную мысль.\n")
				+ right_shift(4) + std::string("Подготовка:\n")
				+ right_shift(5) + std::string("Небольшая колонка текста (90 слов).\n")
				+ right_shift(5) + std::string("Таймер - 2-3 минуты..\n")
				+ right_shift(4) + std::string("Описание задания:\n")
				+ right_shift(5) + std::string("Как можно внимательнее отнестись к деталям.\n")
				+ right_shift(5) + std::string("Выделить главную мысль.\n")
				+ right_shift(5) + std::string("Вслух пересказать как можно подробнее.\n\n")
				+ right_shift(4) + std::string("Техника Мандарина\n")
				+ right_shift(4) + std::string("Полетели!\n")
			     ),7,3,13);

	std::getchar();	


	display_text_in_page((std::string("Упражнение 5 завершено.\n\n")
				+ right_shift(4) + std::string(" У вас всё получилось!\n")
				+ right_shift(4) + std::string("        Молодец!\n")
			     ),4,8,4);

	std::getchar();

}
void LESSONS::lesson6()
{


	display_text_in_page((std::string("Task 6\n\n") 
				+ right_shift(4) + std::string("\"Пары слов. Чётные числа.\" (расширение сферического зрения)\n")
				+ right_shift(4) + std::string("Подготовка:\n")
				+ right_shift(5) + std::string("Время - 3 раза.\n")
				+ right_shift(4) + std::string("Описание задания:\n")
				+ right_shift(5) + std::string("Запускайте программу.\n\n")
				+ right_shift(4) + std::string("Техника Мандарина\n")
				+ right_shift(4) + std::string("Полетели!\n")
			     ),7,3,10);

	std::getchar();	


	display_text_in_page((std::string("Упражнение 6 завершено.\n\n")
				+ right_shift(4) + std::string(" У вас всё получилось!\n")
				+ right_shift(4) + std::string("        Молодец!\n")
			     ),4,8,4);

	std::getchar();



}
void  LESSONS::lesson7()
{

	display_text_in_page((std::string("Task 7\n\n") 
				+ right_shift(4) + std::string("\"Зеленая точка\".(упражнение на концентрацию).\n")
				+ right_shift(4) + std::string("Подготовка:\n")
				+ right_shift(5) + std::string("Программа Скорочтение. Тренажёр >> Зелёная точка.\n")
				+ right_shift(5) + std::string("Таймер - 10 минут.\n")
				+ right_shift(4) + std::string("Описание задания:\n")
				+ right_shift(5) + std::string("Запустите программу.\n\n")
				+ right_shift(4) + std::string("Техника Мандарина\n")
				+ right_shift(4) + std::string("Начинайте!\n")
			     ),7,3,11);

	std::getchar();	


	display_text_in_page((std::string("Упражнение 7 завершено.\n\n")
				+ right_shift(4) + std::string(" У вас всё получилось!\n")
				+ right_shift(4) + std::string("        Молодец!\n")
			     ),4,8,4);

	std::getchar();

}
void LESSONS::lesson8()
{

	display_text_in_page((std::string("Task 8\n\n") 
				+ right_shift(4) + std::string("\"Запомни число\".(упражнение на внимательность).\n")
				+ right_shift(4) + std::string("Подготовка:\n")
				+ right_shift(5) + std::string("Программа Скорочтение. Тренажёр >> Зелёная точка.\n")
				+ right_shift(5) + std::string("Время - 3 раза.\n")
				+ right_shift(4) + std::string("Описание задания:\n")
				+ right_shift(5) + std::string("Запустите программу.\n\n")
				+ right_shift(4) + std::string("Техника Мандарина\n")
				+ right_shift(4) + std::string("Начинайте!\n")
			     ),7,3,11);

	std::getchar();	


	display_text_in_page((std::string("Упражнение 8 завершено.\n\n")
				+ right_shift(4) + std::string(" У вас всё получилось!\n")
				+ right_shift(4) + std::string("        Молодец!\n")
			     ),4,8,4);

	std::getchar();







}
void  LESSONS::lesson9()
{
	
	display_text_in_page((std::string("Task 9\n\n") 
				+ right_shift(4) + std::string("Упражнение на память. Запомнить предмет.\n")
				+ right_shift(4) + std::string("Подготовка:\n")
				+ right_shift(5) + std::string("Любой предмет.\n")
				+ right_shift(5) + std::string("Таймер - по 1 минуте 4 раза.\n")
				+ right_shift(4) + std::string("Описание задания:\n")
				+ right_shift(5) + std::string("Сначала рассматриваете предмет.\n")
				+ right_shift(5) + std::string("Потом закрываете глаза и воспроизводите в деталях.\n\n")
				+ right_shift(4) + std::string("Техника Мандарина\n")
				+ right_shift(4) + std::string("Поехали!\n")
			     ),7,3,12);

	std::getchar();	

	display_text_in_page("Запустить таймер?\n\t\t\t\tYes(1)/No(2)",4,8,1);

	int32_t answer = 1;
	input(answer);
	std::getchar();
	if(answer == 1)
	{
		for(size_t i=0; i<4; ++i)
		{
			display_text_in_page("Input seconds:",4,8,0);	

			int32_t seconds=1;
			input(seconds);
			run_timer(seconds); //seconds

			int answer2 = 1;
			display_text_in_page("Продолжить упражнение?\n\t\t\t\tYes(1)/No(2)",4,8,1);

			input(answer2);
			std::getchar();
			if(answer2 == 2)
			{
				break;
			}


		}

	}


	display_text_in_page((std::string("Упражнение 9 завершено.\n\n")
				+ right_shift(4) + std::string(" У вас всё получилось!\n")
				+ right_shift(4) + std::string("        Молодец!\n")
			     ),4,8,4);

	std::getchar();

}
void  LESSONS::lesson10()
{
	
	display_text_in_page((std::string("Task 10\n\n") 
				+ right_shift(4) + std::string("Замечаем неодинаковость в крайних буквах.\n")
				+ right_shift(4) + std::string("Подготовка:\n")
				+ right_shift(5) + std::string("Программа Скорочтение. Тренажёр >> Поле зрения.\n")
				+ right_shift(5) + std::string("Таймер - 3 раза.\n")
				+ right_shift(4) + std::string("Описание задания:\n")
				+ right_shift(5) + std::string("Запустите задание.\n\n")
				+ right_shift(4) + std::string("Техника Мандарина\n")
				+ right_shift(4) + std::string("Поехали!\n")
			     ),7,3,11);

	std::getchar();	


	display_text_in_page((std::string("Упражнение 10 завершено.\n\n")
				+ right_shift(4) + std::string(" У вас всё получилось!\n")
				+ right_shift(4) + std::string("        Молодец!\n")
			     ),4,8,4);

	std::getchar();


}
void  LESSONS::lesson11()
{
	
	display_text_in_page((std::string("Task 11\n\n") 
				+ right_shift(4) + std::string("Запоминаем художественную открытку.\n")
				+ right_shift(4) + std::string("Подготовка:\n")
				+ right_shift(5) + std::string("Сайт с картинками.\n")
				+ right_shift(5) + std::string("Таймер - 20 секунд по 3 раза.\n")
				+ right_shift(4) + std::string("Описание задания:\n")
				+ right_shift(5) + std::string("Берем открытку.\n")
				+ right_shift(5) + std::string("Смотрим в центр и пытаемся увидеть изображения по краям.\n")
				+ right_shift(5) + std::string("Закройте глаза и воспроизведите в памяти, что увидели,\n")
				+ right_shift(6) + std::string("с предельной точностью.\n")
				+ right_shift(5) + std::string("Про себя начинаем отсчёт до 20.\n\n")
				+ right_shift(4) + std::string("Техника Мандарина\n")
				+ right_shift(4) + std::string("Вперёд!\n")
			     ),7,3,15);

	std::getchar();	


	display_text_in_page((std::string("Упражнение 11 завершено.\n\n")
				+ right_shift(4) + std::string(" У вас всё получилось!\n")
				+ right_shift(4) + std::string("        Молодец!\n")
			     ),4,8,4);

	std::getchar();


}
void  LESSONS::lesson12()
{
	display_text_in_page((std::string("Task 12\n\n") 
				+ right_shift(4) + std::string("Таблица Шульте.\n")
				+ right_shift(4) + std::string("Подготовка:\n")
				+ right_shift(5) + std::string("Программа Скорочтение.\n")
				+ right_shift(6) + std::string("Тренажёр >> Таблица Шульте.\n")
				+ right_shift(5) + std::string("Таймер - 3 раза.\n")
				+ right_shift(4) + std::string("Описание задания:\n")
				+ right_shift(5) + std::string("Запустите программу.\n\n")
				+ right_shift(4) + std::string("Расслабиться с помощью техники мандарина.\n")
				+ right_shift(4) + std::string("Начали!\n")
			     ),7,3,13);

	std::getchar();	


	display_text_in_page((std::string("Упражнение 12 завершено.\n\n")
				+ right_shift(4) + std::string(" У вас всё получилось!\n")
				+ right_shift(4) + std::string("        Молодец!\n")
			     ),4,8,4);

	std::getchar();

}


void  LESSONS::lesson13()
{
	display_text_in_page((std::string("Task 13\n\n") 
				+ right_shift(4) + std::string("Выделить главную мысль в тексте.\n")
				+ right_shift(4) + std::string("Подготовка:\n")
				+ right_shift(5) + std::string("Маленькая статья (90 слов).\n")
				+ right_shift(5) + std::string("Таймер - 45 секунд.\n")
				+ right_shift(4) + std::string("Описание задания:\n")
				+ right_shift(5) + std::string("Быстро, но вдумчиво прочитать.\n")
				+ right_shift(5) + std::string("Выделить главные мысли текста.\n\n")
				+ right_shift(4) + std::string("Расслабиться с помощью техники мандарина.\n")
				+ right_shift(4) + std::string("Вы справитесь!\n")
			     ),7,3,13);

	std::getchar();	

	int32_t answer = 1;
	display_text_in_page("Установить таймер?\n\t\t\t\tYes(1)/No(2)",4,8,1);
	
	input(answer);
	std::getchar();
	if(answer == 1)
	{
		display_text_in_page("Input seconds:",4,8,0);	

		int32_t seconds=1;
		input(seconds);
		run_timer(seconds); //seconds

	}


	display_text_in_page((std::string("Упражнение 13 завершено.\n\n")
				+ right_shift(4) + std::string(" У вас всё получилось!\n")
				+ right_shift(4) + std::string("        Молодец!\n")
			     ),4,8,4);

	std::getchar();

}

void  LESSONS::lesson14()
{

	display_text_in_page((std::string("Task 14\n\n") 
				+ right_shift(4) + std::string("Чтение литературы.\n")
				+ right_shift(4) + std::string("Подготовка:\n")
				+ right_shift(5) + std::string("Научно-популярная литература,\n")
				+ right_shift(6) + std::string("или общественно-политическая.\n")
				+ right_shift(6) + std::string("или литература по специальности.\n")
				+ right_shift(5) + std::string("Таймер - 25-30 страниц.\n")
				+ right_shift(4) + std::string("Описание задания:\n")
				+ right_shift(5) + std::string("После прочтения логически обрабатывать информацию,\n")
				+ right_shift(6) + std::string("выделить главные мысли.\n\n")
				+ right_shift(4) + std::string("Расслабиться с помощью техники мандарина.\n")
				+ right_shift(4) + std::string("3! 2! 1! ПУСК!!!\n")
			     ),7,3,14);

	std::getchar();	


	display_text_in_page((std::string("Упражнение 14 завершено.\n\n")
				+ right_shift(4) + std::string(" У вас всё получилось!\n")
				+ right_shift(4) + std::string("        Молодец!\n")
			     ),4,8,4);

	std::getchar();
}
/*
void lesson15()
{
	std:: cout << "\tРасширяем поле зрения.\n";
	std::cout << "\t\tТаймер - 3 раза.\n";
	std::cout << "\t\tПрограмма Скорочтение. Тренажёр >> Поле зрения.\n";

	std::cout << "\t\t\t1.Расслабиться с помощью техники мандарина.\n";
	std::cout << "\t\t\t2.Задание:\n";
	std::cout << "\t\t\t\tЗамечаем неодинаковость в крайних буквах.\n";
	std::cout << "\t\t\t3.Приступаем к заданию!\n";


	std::cout << "\n\n\n\n\n";
	std::cout << "\n\n\n\n\n";
	std::cout << "\n\n\n\n\n";
}
void lesson16()
{
	std:: cout << "\tОграничиваем количество фиксаций на строчке.\n";
	std:: cout << "\t\tПодготовка:\n";
	std::cout << "\t\t\tВремя 5-8 минут.\n";
	std::cout << "\t\t\tЖурнал Наука и жизнь.\n";
	std::cout << "\t\t\tЦветной карандаш.\n";
	std:: cout << "\t\tОписание задания:\n";
	std::cout << "\t\t\tРазделите текст мысленно на 4 колонки (цветным карандашом).\n";
	std::cout << "\t\t\tСтарайтесь делать по одной фиксации, выделяя ключевые слова.\n";
	std::cout << "\t\t\tСтрочку должны научиться читать за 4 фиксации.\n";
	std::cout << "\t\t\t\tЧерез неделю страницу книги разделите на 3 колонки.\n";
	std::cout << "\t\t\t\tЧерез 4 недели на 2 колонки.\n";
	std:: cout << "\t\t1.Техника мандарина.\n";
	std:: cout << "\t\t2.Расслабтесь, думайте о теме текста.\n";
	std:: cout << "\t\t3.Начали!\n";


	std::cout << "\n\n\n\n\n";
	std::cout << "\n\n\n\n\n";
	std::cout << "\n\n\n\n\n";
}
void lesson17()
{
	std:: cout << "\tПоиск несоответствующих пар.\n";
	std:: cout << "\t\tПодготовка:\n";
	std::cout << "\t\t\tПо 2 раза - каждое упражнение.\n";
	std::cout << "\t\t\tПрограмма Скорочтение >> Пары слов.\n";
	std::cout << "\t\t\tПрограмма Скорочтение >> Чётные числа.\n";
	std:: cout << "\t\tОписание задания:\n";
	std::cout << "\t\t\tПопеременно включаем упражнение по 2 раза.\n";
	std:: cout << "\t\t1.Техника мандарина.\n";
	std:: cout << "\t\t2.Расслабтесь, думайте о теме текста.\n";
	std:: cout << "\t\t3.Начали!\n";


	std::cout << "\n\n\n\n\n";
	std::cout << "\n\n\n\n\n";
	std::cout << "\n\n\n\n\n";
}

void lesson18()
{
	std:: cout << "\tЧтение сложного текста без регрессии.\n";
	std:: cout << "\t\tПодготовка:\n";
	std::cout << "\t\t\tСтраница сложного текста.\n";
	std::cout << "\t\t\tЛист бумаги, покрывающий ширину отрывка.\n";
	std:: cout << "\t\tОписание задания:\n";
	std::cout << "\t\t\tНайдите отрывки с трудной и незнакомой лексикой не по вашей специальности.\n";
	std::cout << "\t\t\tЧтение со скоростью 250 знаков в минуту (бодро).\n";
	std::cout << "\t\t\tПри чтении листом бумаги закрывайте прочитанные строки, двигаясь сверху вниз.\n";
	std:: cout << "\t\t1.Техника мандарина.\n";
	std:: cout << "\t\t2.Расслабтесь, думайте о теме текста.\n";
	std:: cout << "\t\t3.Начали!\n";


	std::cout << "\n\n\n\n\n";
	std::cout << "\n\n\n\n\n";
	std::cout << "\n\n\n\n\n";
}
void lesson19()
{
	std:: cout << "\tЧтение вслух.\n";
	std:: cout << "\t\tПодготовка:\n";
	std::cout << "\t\t\t2 страницы любого текста.\n";
	std::cout << "\t\t\tЛист бумаги, покрывающий ширину отрывка.\n";
	std:: cout << "\t\tОписание задания:\n";
	std::cout << "\t\t\tЧитайте вслух текст выразительно, чётко произнося каждое слово,\n";
	std::cout << "\t\t\t\tне повторяясь и не заикаясь.\n";
	std::cout << "\t\t\tНужно добиваться хорошего плавного чтения  без подготовки в разговорном темпе.\n";
	std::cout << "\t\t\t\tЧерез неделю страницу книги разделите на 3 колонки.\n";
	std::cout << "\t\t\t\tЧерез 4 недели на 2 колонки.\n";
	std:: cout << "\t\t1.Техника мандарина.\n";
	std:: cout << "\t\t2.Расслабтесь, думайте о теме текста.\n";
	std:: cout << "\t\t3.Начали!\n";


	std::cout << "\n\n\n\n\n";
	std::cout << "\n\n\n\n\n";
	std::cout << "\n\n\n\n\n";
}

void lesson19()
{
	std:: cout << "\tЧтение столбиков с шаблоном 1.\n";
	std:: cout << "\t\tПодготовка:\n";
	std::cout << "\t\t\tВремя 3-5 минут.\n";
	std::cout << "\t\t\tТекст столбиком.\n";
	std::cout << "\t\t\tШаблон 1.\n";
	std:: cout << "\t\tОписание задания:\n";
	std::cout << "\t\t\tСо скоростью одна секунда на колонку\n";
	std::cout << "\t\t\t\tдвигать шаблон сверху вниз\n";
	std::cout << "\t\t\t\tсо скоростью одна секунда на колонку.\n";
	std::cout << "\t\t\tЧерез прорез шаблона нужно \"схватить,узнать\" слова\n";
	std::cout << "\t\t\t\tбез прочитывания.\n";
	std:: cout << "\t\t1.Техника мандарина.\n";
	std:: cout << "\t\t2.Расслабтесь, думайте о теме текста.\n";
	std:: cout << "\t\t3.Начали!\n";


	std::cout << "\n\n\n\n\n";
	std::cout << "\n\n\n\n\n";
	std::cout << "\n\n\n\n\n";
}
void lesson20()
{
	std:: cout << "\tПоиск несоответствующих пар.\n";
	std:: cout << "\t\tПодготовка:\n";
	std::cout << "\t\t\tПо 2 раза - каждое упражнение.\n";
	std::cout << "\t\t\tПрограмма Скорочтение >> Пары слов.\n";
	std::cout << "\t\t\tПрограмма Скорочтение >> Чётные числа.\n";
	std:: cout << "\t\tОписание задания:\n";
	std::cout << "\t\t\tПопеременно включаем упражнение по 2 раза.\n";
	std:: cout << "\t\t1.Техника мандарина.\n";
	std:: cout << "\t\t2.Расслабтесь, думайте о теме текста.\n";
	std:: cout << "\t\t3.Начали!\n";


	std::cout << "\n\n\n\n\n";
	std::cout << "\n\n\n\n\n";
	std::cout << "\n\n\n\n\n";
}
void lesson21()
{
	std:: cout << "\tИщем в тексте определённые слова.\n";
	std:: cout << "\t\tПодготовка:\n";
	std::cout << "\t\t\tВыбрать 20 строчек текста.\n";
	std:: cout << "\t\tОписание задания:\n";
	std::cout << "\t\t\t1.За 2 секунды найдите все названия\n";
	std::cout << "\t\t\t\tвидов чего-либо (птиц, машин),\n";
	std::cout << "\t\t\t\tвсе прилагательные,все глаголы.\n";
	std::cout << "\t\t\t2.За 2 секунды подсчитайте сначала глаголы,\n";
	std::cout << "\t\t\t\tзатем - прилагательные,\n";
	std::cout << "\t\t\t\tзатем - существительные.\n";
	std::cout << "\t\t\t3.За 3 секунды найдите ключевые слова строчек.\n";
	std:: cout << "\t\t1.Техника мандарина.\n";
	std:: cout << "\t\t2.Расслабьтесь, думайте о теме текста.\n";
	std:: cout << "\t\t3.Начали!\n";


	std::string FILENAME = "russian_words.txt";
	std::vector<std::string> source_list_of_words;
	//get_all_lines_from_output_file(FILENAME,source_list_of_words);

	int32_t number_of_words = 20;
	std::vector<std::string> set_of_words;
	create_set_of_words(source_list_of_words,
		number_of_words,set_of_words);
	
	std::cout << "\t\t\t1.За 2 секунды найдите все названия\n";
	std::cout << "\t\t\t\tвидов чего-либо (птиц, машин),\n";
	void display_n();
	std::getchar();
	display_set_of_words(set_of_words);
	std::getchar();

	std::cout << "\t\t\t1.За 2 секунды найдите все прилагательные.\n";
	void display_n();
	std::getchar();
	display_set_of_words(set_of_words);
	std::getchar();


	std::cout << "\t\t\t1.За 2 секунды найдите все глаголы.\n";
	void display_n();
	std::getchar();
	display_set_of_words(set_of_words);
	std::getchar();
	
	set_of_words.clear();
	create_set_of_words(source_list_of_words,
		number_of_words,set_of_words);

	
	std::cout << "\t\t\tЗа 2 секунды подсчитайте  глаголы.\n";
	void display_n();
	std::getchar();
	display_set_of_words(set_of_words);
	std::getchar();
	
	std::cout << "\t\t\t\tЗа 2 секунды подсчитайте прилагательные.\n";
	void display_n();
	std::getchar();
	display_set_of_words(set_of_words);
	std::getchar();

	std::cout << "\t\t\t\tЗа 2 секунды подсчитайте существительные.\n";
	void display_n();
	std::getchar();
	display_set_of_words(set_of_words);
	std::getchar();

	set_of_words.clear();
	create_set_of_words(source_list_of_words,
		number_of_words,set_of_words);
	
	std::cout << "\t\t\t3.За 3 секунды найдите ключевые слова строчек.\n";
	void display_n();
	std::getchar();
	display_set_of_words(set_of_words);
	std::getchar();


}

*/		
	
	

		
			 
		
