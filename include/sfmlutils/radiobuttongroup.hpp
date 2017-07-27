#pragma once

#include <sfmlutils\abstractradiobutton.hpp>

#include <mutils/observer.hpp>

namespace sfmlutils
{
	class RadioButtonGroup : public mutils::Observer, mutils::Observed
	{
	public :
		RadioButtonGroup();
		~RadioButtonGroup();

		virtual void addButton(AbstractRadioButton* button);
		virtual void removeButton(AbstractRadioButton* button);

		virtual AbstractRadioButton* getCurrent() const;

		void setCurrent(AbstractRadioButton* button = nullptr);

	private:
		std::vector<AbstractRadioButton*> buttons_;
		AbstractRadioButton* current_;

		// Inherited via Observer
		virtual void onNotify(mutils::Observed* obs) override;

		void resetAllButtons();
	};
}