#pragma once
#include"Controlador.h"
namespace PC2 {

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
		Image^ iAve;
		Image^ fondo;
		Controlador* aves;
		Graphics^ g;
		//buffer
		BufferedGraphicsContext^ space;

		BufferedGraphics^ buffer;
	private: System::Windows::Forms::Label^ Salvados;
	private: System::Windows::Forms::Label^ Venenosos;
	private: System::Windows::Forms::Timer^ timer1;
	public:
		MyForm(void)
		{
			srand(time(NULL));
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			aves = new Controlador();
			iAve = Image::FromFile("assets/ave.png");
			fondo = Image::FromFile("assets/sky.jpg");
			g = this->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, this->ClientRectangle);
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
			delete aves;
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
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->Salvados = (gcnew System::Windows::Forms::Label());
			this->Venenosos = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// Salvados
			// 
			this->Salvados->AutoSize = true;
			this->Salvados->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Salvados->Location = System::Drawing::Point(179, 158);
			this->Salvados->Name = L"Salvados";
			this->Salvados->Size = System::Drawing::Size(70, 25);
			this->Salvados->TabIndex = 0;
			this->Salvados->Text = L"label1";
			this->Salvados->Visible = false;
			// 
			// Venenosos
			// 
			this->Venenosos->AutoSize = true;
			this->Venenosos->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Venenosos->Location = System::Drawing::Point(181, 218);
			this->Venenosos->Name = L"Venenosos";
			this->Venenosos->Size = System::Drawing::Size(70, 25);
			this->Venenosos->TabIndex = 1;
			this->Venenosos->Text = L"label2";
			this->Venenosos->Visible = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1223, 667);
			this->Controls->Add(this->Venenosos);
			this->Controls->Add(this->Salvados);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Shown += gcnew System::EventHandler(this, &MyForm::MyForm_Shown);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseClick);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		//limpiar
		buffer->Graphics->Clear(Color::White);
		//mover
		aves->mueveAves(buffer->Graphics);
		//dibujar
		int alto = this->Height * 3 / (float)4;
		buffer->Graphics->DrawImage(fondo,0,0,this->Width,alto);
		aves->dibujaAves(buffer->Graphics, iAve);

		//render
		buffer->Render(g);
	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyData) {
		case Keys::A:
			if (!aves->getGo()) {
				aves->agregaAve(iAve, false);
				aves->dibujaUltimaAgregada(g, iAve);
			}
			break;
		case Keys::I:
			if (!aves->getGo()&&aves->getCantidadAves()>0) {
				aves->setGo(true);
				timer1->Enabled = true;
			}
			break;
		case Keys::F:
			aves->setGo(true);
			timer1->Enabled = false;
			Salvados->Text = Convert::ToString("Aves Salvadas:"+ aves->getSalvadas());
			Salvados->Visible = true;
			Venenosos->Text= Convert::ToString("Aves Venenosas Atrapadas: "+aves->getVenenosas());
			Venenosos->Visible = true;
			break;
		}
	}
	private: System::Void MyForm_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (aves->getGo()) {//si el juego esta en curso que verifique los clicks
			aves->click(e->X, e->Y, iAve);
		}
	}
private: System::Void MyForm_Shown(System::Object^ sender, System::EventArgs^ e) {
	int alto = this->Height * 3 / (float)4;
	g->DrawImage(fondo, 0, 0, this->Width , alto);
}
};
}
