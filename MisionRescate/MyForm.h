#pragma once
#include "Controlador.h"
#include "Ganaste.h"
#include "Perdiste.h"
namespace MisionRescate {

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
		int t;
		Controlador^ controlador;
		Controlador^ controlador2;
	public:
		MyForm(int v, int t, int a, int n, int nivel)
		{
			t = (((t * 1000) + clock()) / 1000) + 1; 
			
			InitializeComponent();
			controlador = gcnew Controlador(v,t, a, n, nivel); 
			
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;



	protected:
	private: System::ComponentModel::IContainer^ components;

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
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoValidate = System::Windows::Forms::AutoValidate::EnablePreventFocusChange;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->ClientSize = System::Drawing::Size(784, 761);
			this->MaximumSize = System::Drawing::Size(800, 800);
			this->MinimumSize = System::Drawing::Size(800, 800);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyUp);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) 
	{

	}
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) 
	{
		Graphics^ g = this->CreateGraphics();
		BufferedGraphicsContext^ bfc = BufferedGraphicsManager::Current;
		BufferedGraphics^ bf = bfc->Allocate(g, this->ClientRectangle);
		bf->Graphics->Clear(Color::MediumAquamarine);
		// controlador->Mover(bf->Graphics); 
		controlador->Mostrar(bf->Graphics); 
		bf->Render(g);
		if (controlador->Mover(g) == false)
		{
			this->timer1->Enabled = false;

			if (controlador->GetResul() == false)
			{
				Perdiste^ frn1 = gcnew Perdiste();
				frn1->ShowDialog();
			}
			else
			{
				Ganaste^ frn2 = gcnew Ganaste();
				frn2->ShowDialog();
			}
			this->Close();
		}
	
	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
	{
		controlador->Input(true, e->KeyCode);
	}
	private: System::Void MyForm_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) 
	{
		controlador->Input(false, e->KeyCode);
	}
	
	private: System::Void MyForm_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) 
	{
		controlador->Disparo(e->Button);
	}
    public:
		Controlador^ getControlador(int type) {
			if (type == 1) {
				return controlador;
			}
			else return controlador2;
		}
};
}
