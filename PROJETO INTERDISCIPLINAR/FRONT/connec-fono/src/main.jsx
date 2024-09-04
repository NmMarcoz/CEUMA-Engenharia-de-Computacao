import {StrictMode} from 'react'
import {createRoot} from 'react-dom/client'
import {createBrowserRouter, RouterProvider} from 'react-router-dom';

import App from './pages/LoginPage.jsx'
import './index.css'
import LoginPage from "./pages/LoginPage.jsx";
import RegisterPage from "./pages/RegisterPage.jsx";

const router = createBrowserRouter([
    {
        path: '/',
        element: <LoginPage/>
    },
    {
        path: '/register',
        element: <RegisterPage/>

    }
]);

createRoot(document.getElementById('root')).render(
    <StrictMode>
        <RouterProvider router={router}/>
    </StrictMode>,
)
