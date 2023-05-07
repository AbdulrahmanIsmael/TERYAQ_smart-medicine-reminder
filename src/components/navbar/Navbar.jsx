import { useEffect, useState } from 'react';
import './navbar.scss';
import MenuIcon from '@mui/icons-material/Menu';
import MedicationLiquidIcon from '@mui/icons-material/MedicationLiquid';
import LoginIcon from '@mui/icons-material/Login';
import LogoutIcon from '@mui/icons-material/Logout';
import { Link, NavLink } from 'react-router-dom';
import { signOut } from 'firebase/auth';
import { auth } from '../../firebase/firebase';
import { onAuthStateChanged } from 'firebase/auth';

const Navbar = () => {
  const [showNavbar, setShowNavbar] = useState(false);
  const [isAuth, setIsAuth] = useState(false);

  useEffect(() => {
    onAuthStateChanged(auth, currentUser => {
      if (currentUser) {
        setIsAuth(true);
      }
    });
  }, []);

  const handleShowNavbar = () => {
    setShowNavbar(!showNavbar);
  };

  return (
    <nav className='navbar nav'>
      <div className='nav-container'>
        <Link to='/' className='site-title'>
          <MedicationLiquidIcon />
          <h1>TERYAQ</h1>
        </Link>
        <div className='menu-icon' onClick={handleShowNavbar}>
          <MenuIcon />
        </div>
        <div className={`nav-elements  ${showNavbar && 'active'}`}>
          <ul className='nav-items'>
            <li>
              <NavLink to='/'>Home</NavLink>
            </li>
            <li>
              {isAuth ? (
                <NavLink to='/scheduled'>Scheduled</NavLink>
              ) : (
                // Temporary => will be changing later to the login path | NavLink => Link
                <NavLink to='/scheduled'>Scheduled</NavLink>
              )}
            </li>
            <li>
              {isAuth ? (
                <NavLink to='/emergency'>Emergency</NavLink>
              ) : (
                // Temporary => will be changing later to the login path
                <NavLink to='/emergency'>Emergency</NavLink>
              )}
            </li>
            <li>
              <NavLink to='/about'>About</NavLink>
            </li>
            <li>
              <NavLink to='/help'>Help</NavLink>
            </li>
          </ul>
          <ul className='logging-items'>
            {isAuth ? (
              <>
                <li>
                  <Link
                    onClick={() => {
                      signOut(auth);
                      setIsAuth(false);
                    }}
                    to='/login'
                  >
                    <LogoutIcon sx={{ fontSize: '2rem' }} />
                    Log Out
                  </Link>
                </li>
              </>
            ) : (
              <>
                <li>
                  <NavLink to='/login'>
                    <LoginIcon sx={{ fontSize: '2rem' }} />
                    Log In
                  </NavLink>
                </li>
              </>
            )}
          </ul>
        </div>
      </div>
    </nav>
  );
};

export default Navbar;
