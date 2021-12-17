#pragma once
#include"Controladora.h"
#include"File.h"
namespace ExamenFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:
		//file
		File* file;

		BufferedGraphics^ buffer;
		BufferedGraphicsContext^ space;
		Graphics^ g;
	private: System::Windows::Forms::Panel^ panel1;

		Bitmap^ sprite;
		Bitmap^ pacdot;
		Bitmap^ bonusVelocidad;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ lblVidas;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ lblPacdots;
	private: System::Windows::Forms::Timer^ timerTiempo;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ lblTiempo;

		   Controladora* controladora;
	public:
		MyForm(void)
		{
			srand(time(NULL));
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			file = new File();
			g = panel1->CreateGraphics();

			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, panel1->ClientRectangle);

			sprite = gcnew Bitmap("assets/sprites.png");
			pacdot = gcnew Bitmap("assets/pacdot.png");
			bonusVelocidad = gcnew Bitmap("assets/bonus.png");
			controladora = new Controladora(sprite,pacdot,bonusVelocidad,file->getVidas(),file->getCFantasmas(),file->getCPacdots());
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
			delete file;
		}
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lblVidas = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->lblPacdots = (gcnew System::Windows::Forms::Label());
			this->timerTiempo = (gcnew System::Windows::Forms::Timer(this->components));
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->lblTiempo = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(12, 55);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1117, 546);
			this->panel1->TabIndex = 0;
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(101, 27);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(36, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Vidas:";
			// 
			// lblVidas
			// 
			this->lblVidas->AutoSize = true;
			this->lblVidas->Location = System::Drawing::Point(140, 27);
			this->lblVidas->Name = L"lblVidas";
			this->lblVidas->Size = System::Drawing::Size(13, 13);
			this->lblVidas->TabIndex = 2;
			this->lblVidas->Text = L"0";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(243, 27);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(93, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"PacDots comidos:";
			// 
			// lblPacdots
			// 
			this->lblPacdots->AutoSize = true;
			this->lblPacdots->Location = System::Drawing::Point(339, 27);
			this->lblPacdots->Name = L"lblPacdots";
			this->lblPacdots->Size = System::Drawing::Size(13, 13);
			this->lblPacdots->TabIndex = 4;
			this->lblPacdots->Text = L"0";
			// 
			// timerTiempo
			// 
			this->timerTiempo->Enabled = true;
			this->timerTiempo->Interval = 1000;
			this->timerTiempo->Tick += gcnew System::EventHandler(this, &MyForm::timerTiempo_Tick);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(456, 26);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(45, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Tiempo:";
			// 
			// lblTiempo
			// 
			this->lblTiempo->AutoSize = true;
			this->lblTiempo->Location = System::Drawing::Point(507, 27);
			this->lblTiempo->Name = L"lblTiempo";
			this->lblTiempo->Size = System::Drawing::Size(13, 13);
			this->lblTiempo->TabIndex = 6;
			this->lblTiempo->Text = L"0";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1141, 613);
			this->Controls->Add(this->lblTiempo);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->lblPacdots);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->lblVidas);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->panel1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		//borrar
		buffer->Graphics->Clear(Color::White);
		//mover
		controladora->moverTodo(buffer->Graphics);
		//colision
		controladora->colision(bonusVelocidad);
		//dibujar
		//bonusVelocidad->MakeTransparent(); NO FUNCIONO
		controladora->dibujarTodo(buffer->Graphics, sprite,pacdot,bonusVelocidad);
		lblVidas->Text = controladora->getPacman()->getVidas().ToString();
		lblPacdots->Text = controladora->getPacDotsComidos().ToString();
		lblTiempo->Text = controladora->getTiempo().ToString();
		if (controladora->getPacman()->getVidas() < 1) {
			timer1->Enabled = false;
			lblVidas->Text = controladora->getPacman()->getVidas().ToString();
			MessageBox::Show("Perdiste :(");
			//antes de que la aplicacion se cierre
			file->writeData(controladora->getPacDotsComidos());
			this->Close();
		}
		else if (controladora->getcantidadPacdots()<1) {
			timer1->Enabled = false;
			lblPacdots->Text = controladora->getPacDotsComidos().ToString();
			MessageBox::Show("Ganaste!! :D");
			//antes de que la aplicacion se cierre
			file->writeData(controladora->getPacDotsComidos());
			this->Close();
		}
		else {
			//renderizar
			buffer->Render(g);
		}
	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode) {
		case Keys::Up:
			controladora->getPacman()->mover('W', buffer->Graphics);
			break;
		case Keys::Down:
			controladora->getPacman()->mover('S', buffer->Graphics);
			break;

		case Keys::Right:
			controladora->getPacman()->mover('D', buffer->Graphics);
			break;

		case Keys::Left:
			controladora->getPacman()->mover('A', buffer->Graphics);
			break;
		}
	}
	private: System::Void timerTiempo_Tick(System::Object^ sender, System::EventArgs^ e) {
		controladora->controlTiempo(bonusVelocidad);
	}
};
}
