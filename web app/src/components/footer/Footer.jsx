import './footer.scss';
import FacebookIcon from '@mui/icons-material/Facebook';
import GoogleIcon from '@mui/icons-material/Google';
import LinkedInIcon from '@mui/icons-material/LinkedIn';

function Footer() {
  const currentYear = new Date().getFullYear();

  return (
    <footer>
      <div className='footer-container'>
        {/* <div className='footer-links'>
          <a href='/'>
            <FacebookIcon sx={{ fontSize: '2rem' }} />
          </a>
          <a href='/'>
            <GoogleIcon sx={{ fontSize: '2rem' }} />
          </a>
          <a href='/'>
            <LinkedInIcon sx={{ fontSize: '2rem' }} />
          </a>
        </div> */}
        <div className='footer-copyright'>
          <a href='https:engfac.mans.edu.eg/en/mathematics-and-engineering-physics-department-25'>
            ECE{' '}
          </a>
          <p>© {currentYear} Copyright</p>
        </div>
      </div>
    </footer>
  );
}
export default Footer;
