import {useState} from 'react'
import reactLogo from '../assets/react.svg'
import viteLogo from '/vite.svg'
//import './App.css'
import '../styles/registerPage.css'
import {Link} from "react-router-dom";
import axios, {AxiosError} from "axios";
import LoginPage from "./LoginPage.jsx";


const BASE_URL = "http://localhost:8080"
axios.defaults.baseURL = BASE_URL

function RegisterPage() {
    const [buttonPlaceHolder, setButtonPlaceholder] = useState('insira seu RA')
    const [registerForm, setRegisterForm] = useState({
        name: "",
        email: "",
        password: "",
        cpf: "",
        ra: "",
    });

    const handleFormEdit = async (e) => {

        const {name, value} = e.target;
        setRegisterForm({
            ...registerForm,
            [name]: value,
        })
    }
    const handleSubmit = async (e) => {
        e.preventDefault()
        console.log(registerForm)

        const response = await axios.post(`/patient`, {
                name: registerForm.name,
                email: registerForm.email,
                password: registerForm.password,
                cpf: registerForm.cpf,
                ra: isStudent ? registerForm.ra : null,
                type: isStudent ? "aluno" : "externo"
            },
            {
                headers: {
                    Accept: "application/json",
                    "Content-Type": "application/json",
                    "Access-Control-Allow-Origin": "*",
                }
            }).then(() => {
            console.log("[RESPONSE SUCCESS]: " + response.status + response.data)
            window.alert("Usuário cadastrado com sucesso :" + response.data);
        })
            .catch((err) => {
                if (err instanceof AxiosError) {
                    console.log(err.response.data)
                }

            })


    }

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

                    <form id="form-input-container" onSubmit={handleSubmit}>
                        <input name="email" placeholder="insira seu email" id="login-input"
                               defaultValue={registerForm.email}
                               onChange={event => handleFormEdit(event)}/>
                        <input name="password" placeholder="insira sua senha" id="login-input"
                               defaultValue={registerForm.password}
                               onChange={event => handleFormEdit(event)}
                               type="password"/>
                        <input name="ra" placeholder="insira seu ra" id="login-input" value={registerForm.ra}
                               onChange={event => handleFormEdit(event)} className="toggle-button"
                               style={{display: isStudent ? 'flex' : 'none'}}/>
                        <input name="name" placeholder="insira seu nome" id="login-input" value={registerForm.name}
                               onChange={event => handleFormEdit(event)}/>
                        <input name="cpf" placeholder="insira seu cpf" id="login-input" value={registerForm.cpf}
                               onChange={event => handleFormEdit(event)}/>
                        <button type="submit"> cadastrar</button>
                    </form>


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
