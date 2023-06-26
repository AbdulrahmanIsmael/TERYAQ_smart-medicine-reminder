import { useEffect, useState } from 'react';
import { Routes, Route } from 'react-router-dom';
import Navbar from './components/navbar/Navbar';
import Footer from './components/footer/Footer';
import Home from './components/home/Home';
import Preloader from './components/preloader/Preloader';
import About from './components/about/About';
import Help from './components/help/Help';
import Login from './components/login/Login';
import Emergency from './components/emergency/Emergency';
import Scheduled from './components/scheduled/Scheduled';
import { onAuthStateChanged } from 'firebase/auth';
import { auth } from './firebase/firebase';

function App() {
  const [preloader, setPreloader] = useState(true);
  // eslint-disable-next-line no-unused-vars
  const [isAuth, setIsAuth] = useState(false);

  // Preloader rendering
  useEffect(() => {
    setTimeout(() => {
      setPreloader(false);
    }, 2500);
  }, []);

  useEffect(() => {
    onAuthStateChanged(auth, currentUser => {
      if (currentUser) {
        setIsAuth(true);
      }
    });
  }, []);
  return (
    <>
      <Navbar />
      {preloader ? (
        <Preloader />
      ) : (
        <div>
          <div className='container'>
            <Routes>
              <Route path='/' element={<Home />} />
              <Route path='/about' element={<About />} />
              <Route path='/help' element={<Help />} />
              <Route path='/login' element={<Login />} />
              <Route path='/emergency' element={<Emergency />} />
              <Route path='/scheduled' element={<Scheduled />} />
            </Routes>
          </div>
        </div>
      )}
      <Footer />
    </>
  );
}

export default App;
