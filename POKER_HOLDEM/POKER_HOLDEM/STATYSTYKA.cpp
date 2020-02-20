#include "STATYSTYKA.h"


STATYSTYKA::STATYSTYKA()
{
}

STATYSTYKA::STATYSTYKA(std::shared_ptr<lista> head1) :head(head1)
{
	head->next = head->prev = head;
}

void STATYSTYKA::ustaw(std::shared_ptr<lista> head1)
{
	head = head1;
	head->next = head->prev = head;
}

STATYSTYKA::~STATYSTYKA()
{
	while (head->next->next != head)
	{
		head->next->prev = head->prev;
		head->prev->next = head->next;
		std::shared_ptr<lista> tmp = head;
		head = head->next;
		tmp.reset();
	}
	if (head->next != head)
	{
		head->next->prev = nullptr;
		head->next->next = nullptr;
		head->prev = head;
		head->next.reset();
		head->next = head;
	}
	head->next = nullptr;
	head->prev = nullptr;
	head.reset();
}

void STATYSTYKA::push_back(int kwota_wygrana)
{
	if (head == nullptr)
		head = std::shared_ptr<lista>(new lista(kwota_wygrana, head, head));
	else
	{
		std::shared_ptr<lista> tmp = head->prev;
		head->prev = std::shared_ptr<lista>(new lista(kwota_wygrana, head, tmp));
		head->next = head->prev;
	}
}

int STATYSTYKA::zwroc()
{
	std::shared_ptr<lista> tmp = head;
	tmp = tmp->next;
	return tmp.get()->kwota_wygrana;
}
