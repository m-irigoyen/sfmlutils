#include <sfmlutils\radiobuttongroup.hpp>

#include <mutils/assert.hpp>

#include <algorithm>

namespace sfmlutils
{
	using buttonVec = std::vector<AbstractRadioButton*>;

	buttonVec::iterator find(buttonVec& vec, AbstractRadioButton* button)
	{
		return std::find(vec.begin(), vec.end(), button);
	}

	RadioButtonGroup::RadioButtonGroup()
		: current_(nullptr)
	{
	}

	RadioButtonGroup::~RadioButtonGroup()
	{
	}

	void RadioButtonGroup::addButton(AbstractRadioButton * button)
	{
		if (find(buttons_, button) == buttons_.end())
		{
			buttons_.push_back(button);
			button->registerObserver(this);
		}
	}

	void RadioButtonGroup::removeButton(AbstractRadioButton * button)
	{
		buttonVec::iterator it = find(buttons_, button);
		if (it != buttons_.end())
		{
			buttons_.erase(it);
			button->unregisterObserver(this);
			if (current_ == button)
			{
				current_ = nullptr;
			}
		}
	}

	AbstractRadioButton* RadioButtonGroup::getCurrent() const
	{
		return current_;
	}

	void RadioButtonGroup::setCurrent(AbstractRadioButton * button)
	{
		buttonVec::iterator it = find(buttons_, button);
		if (it != buttons_.end())
		{
			if (current_ != button)
			{
				if (current_)
				{
					current_->forceState(AbstractPushButton::STATE::REST);
				}
				current_ = button;
				current_->forceState(AbstractPushButton::STATE::CLICKED);
				notifyObservers();
			}
		}
	}

	void RadioButtonGroup::onNotify(mutils::Observed* obs)
	{
		AbstractRadioButton* b = dynamic_cast<AbstractRadioButton*>(obs);
		MUTILS_ASSERT(b && (find(buttons_, b) != buttons_.end()));

		if (b != current_)
		{
			resetAllButtons();
			setCurrent(b);
		}
	}

	void RadioButtonGroup::resetAllButtons()
	{
		for (AbstractRadioButton* b : buttons_)
		{
			b->forceState(AbstractPushButton::STATE::REST);
		}
		current_ = nullptr;
	}
}