import {useState} from 'react'
import reactLogo from '../assets/react.svg'
import viteLogo from '/vite.svg'
//import './App.css'
import '../styles/registerPage.css'
import {Link} from "react-router-dom";
import LoginPage from "./LoginPage.jsx";

function RegisterPage() {
    const [buttonPlaceHolder, setButtonPlaceholder] = useState('insira seu RA')
    const [isStudent, setIsStudent] = useState(true);
    // pra trocar o placeholder de RA pra Email e vice versa

    return (
        <div id="main-container">
            <div id="left-container">
                <div id="left-title-container">
                    <h1>
                        Nunca foi tão fácil <br/> de agendar sua consultas <br/>
                        de fonoaudiologia no CEUMA.
                    </h1>
                    <p>
                        Cadastre-se na plataforma para consultar
                    </p>
                </div>
            </div>
            <div id="right-container">
                <div id="form-container">
                    <div id="form-header-container">
                        <h2>
                            Selecione o seu tipo de cadastro abaixo.
                        </h2>
                        <div id="login-header-container">
                            <h1>
                                Registrar
                            </h1>
                            <div id="login-header-button-container">
                                <button onClick={() => setIsStudent(isStudent => true)}>
                                    aluno
                                </button>
                                <button onClick={() => setIsStudent(isStudent => false)}>
                                    externo
                                </button>
                            </div>
                        </div>

                    </div>
                    <div id="form-input-container">
                        <input placeholder="insira seu email" id="login-input"/>
                        <input placeholder="insira sua senha" id="login-input"/>
                        <input placeholder="insira seu ra" id="login-input" className="toggle-button" style={{display : isStudent? 'flex':'none' }}/>
                        <input placeholder="insira seu nome" id="login-input"/>
                        <input placeholder="insira seu cpf" id="login-input"/>
                        <button> cadastrar </button>

                    </div>
                    <div id="form-footer-container">
                        Já possui uma conta?
                        <Link to="/">
                            logar
                        </Link>
                    </div>

                </div>
            </div>

        </div>

    )
}

export default RegisterPage
